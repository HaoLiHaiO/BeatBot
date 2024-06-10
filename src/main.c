#include "gen-rand-sound.h"
#include "play-sound.h"
#include "utils/term-raw-mode.h"
#include "utils/non-blocking-mode.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    setTerminalRawMode(1);
    setNonBlockingMode(1);

    while (1) {
        generateRandomSound("noteA.wav");
        generateRandomSound("noteB.wav");
        generateRandomSound("noteC.wav");

        playSound("noteA.wav");
        playSound("noteB.wav");
        playSound("noteC.wav");

        int c = getchar();
        if (c == 'q') {
            break;
        }

        usleep(100000);
    }

    setNonBlockingMode(0);
    setTerminalRawMode(0);

    return 0;
}
