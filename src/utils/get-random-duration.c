#include "get-random-duration.h"
#include <stdlib.h>
#include <time.h>

float getRandomDuration(int tempo) {
    float duration_factors[] = {4.0, 2.0, 1.0, 0.5, 0.25};  // Whole, Half, Quarter, Eighth, Sixteenth
    size_t num_factors = sizeof(duration_factors) / sizeof(duration_factors[0]);

    srand(time(NULL));
    float random_duration_factor = duration_factors[rand() % num_factors];

    float beat_duration = 60.0 / tempo;
    return beat_duration * random_duration_factor;
}
