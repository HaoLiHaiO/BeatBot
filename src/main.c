#include <SDL2/SDL.h>
#include <stdio.h>

void generateSound(const char* filename, int frequency) {
    char command[100];
    snprintf(command, sizeof(command), "sox -n -r 44100  -c 1 %s synth 1 sine %d", filename, frequency);
    system(command);
}

void playSound(const char* filename) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    if (SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength) == NULL) {
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

    SDL_Delay(1000);

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
}

int main() {
    generateSound("noteA.wav", 440); // A4
    playSound("noteA.wav");
    generateSound("noteB.wav", 494); // B4
    playSound("noteB.wav");
    generateSound("noteC.wav", 523); // C5
    playSound("noteC.wav");

    generateSound("hello.wav", 700);
    playSound("hello.wav");
    return 0;
}
