#include "get-random-chord.h"
#include "get-random-frequency.h"
#include "get-random-duration.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandomChord(char *command, size_t size) {
    int tempo = 120;

    int frequencies[] = {
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency(),
        getRandomFrequency()
    };

    float duration = getRandomDuration(tempo);

    snprintf(command, size, "sox -n synth pl %d pl %d pl %d pl %d pl %d pl %d", 
             frequencies[0], frequencies[1], frequencies[2], 
             frequencies[3], frequencies[4], frequencies[5]);
}
