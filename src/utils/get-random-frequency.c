#include "get-random-frequency.h"
#include <stdlib.h>
#include <time.h>

int getRandomFrequency() {
    int notes[] = {440, 494, 523, 587, 659, 698, 784};  // A4, B4, C5, D5, E5, F5, G5
    size_t num_notes = sizeof(notes) / sizeof(notes[0]);

    srand(time(NULL));
    return notes[rand() % num_notes];
}
