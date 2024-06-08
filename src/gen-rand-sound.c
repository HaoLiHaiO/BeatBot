#include "gen-rand-sound.h"
#include "utils/get-full-path.h"
#include "utils/get-random-chord.h"
#include "utils/get-random-duration.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096
#define MAX_COMMAND_LENGTH 8192

void generateRandomSound(const char* filename) {
    char absPath[MAX_PATH_LENGTH];
    getFullPath("/assets", absPath, sizeof(absPath));

    struct stat st = {0};
    if (stat(absPath, &st) == -1) {
        if (mkdir(absPath, 0700) != 0) {
            perror("mkdir");
            return;
        }
    }

    printf("Assets directory: %s\n", absPath);

    int tempo = 120;
    float duration = getRandomDuration(tempo);

    char chord_command[MAX_COMMAND_LENGTH];
    getRandomChord(chord_command, sizeof(chord_command), duration);

    char command[MAX_COMMAND_LENGTH];
    int ret = snprintf(command, sizeof(command), "sox -n -r 44100 -c 1 %s/%s %s", absPath, filename, chord_command);
    if (ret < 0 || ret >= sizeof(command)) {
        fprintf(stderr, "Command buffer too small or snprintf error!\n");
        return;
    }

    printf("Executing command: %s\n", command);
    int result = system(command);
    if (result == -1) {
        perror("system");
    } else {
        printf("Command executed with result: %d\n", result);
    }

    char filepath[MAX_PATH_LENGTH];
    ret = snprintf(filepath, sizeof(filepath), "%s/%s", absPath, filename);
    if (ret < 0 || ret >= sizeof(filepath)) {
        fprintf(stderr, "Filepath buffer too small or snprintf error!\n");
        return;
    }

    if (access(filepath, F_OK) == 0) {
        printf("File created: %s\n", filepath);
    } else {
        printf("Failed to create file: %s\n", filepath);
    }
}
