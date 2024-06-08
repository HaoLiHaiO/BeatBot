#include "get-random-chord.h"
#include "get-random-frequency.h"
#include "get-random-duration.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandomChord(char *command, size_t size, float duration) {
    int frequencies[] = {
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency()
    };

    int ret = snprintf(command, size, "synth %.2f pl %d pl %d pl %d pl %d pl %d pl %d", 
                       duration, frequencies[0], frequencies[1], frequencies[2], 
                       frequencies[3], frequencies[4], frequencies[5]);
    if (ret < 0 || ret >= size) {
        fprintf(stderr, "Chord command buffer too small or snprintf error!\n");
    }
}
