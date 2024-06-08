// src/play-sound.c
#include "play-sound.h"
#include "utils/get-full-path.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h> // Use this for PATH_MAX on Linux

void playSound(const char* filename) {
    char absPath[PATH_MAX];
    getFullPath("/assets", absPath, sizeof(absPath));

    // Construct the full file path
    char filepath[PATH_MAX + 64];
    snprintf(filepath, sizeof(filepath), "%s/%s", absPath, filename);
    printf("Playing file: %s\n", filepath);

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    if (SDL_LoadWAV(filepath, &wavSpec, &wavBuffer, &wavLength) == NULL) {
        printf("Failed to load wav file! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        printf("Failed to open audio device! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    if (success < 0) {
        printf("Failed to play sound! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_PauseAudioDevice(deviceId, 0);

    SDL_Delay(1000); // Wait for the sound to finish

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
}
