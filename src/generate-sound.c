// src/generate-sound.c
#include "generate-sound.h"
#include "utils/get-full-path.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <unistd.h>
#include <fcntl.h>

void generateSound(const char* filename, int frequency) {
    char absPath[PATH_MAX + 64];
    getFullPath("/assets", absPath, sizeof(absPath));

    // Create assets directory if it does not exist
    struct stat st = {0};
    if (stat(absPath, &st) == -1) {
        if (mkdir(absPath, 0700) != 0) {
            perror("mkdir");
            return;
        }
    }

    // Print the full path for debugging
    printf("Assets directory: %s\n", absPath);

    // Construct the command
    char command[PATH_MAX + 150];
    int ret = snprintf(command, sizeof(command), "sox -n -r 44100 -c 1 %s/%s synth 1 sine %d", absPath, filename, frequency);
    if (ret >= sizeof(command)) {
        fprintf(stderr, "Command buffer too small!\n");
        return;
    }

    printf("Executing command: %s\n", command);
    int result = system(command);
    if (result == -1) {
        perror("system");
    } else {
        printf("Command executed with result: %d\n", result);
    }

    // Verify if the file was created
    char filepath[PATH_MAX + 150];
    snprintf(filepath, sizeof(filepath), "%s/%s", absPath, filename);
    if (access(filepath, F_OK) == 0) {
        printf("File created: %s\n", filepath);
    } else {
        printf("Failed to create file: %s\n", filepath);
    }
}
