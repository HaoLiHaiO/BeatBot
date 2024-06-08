#include "gen-rand-sound.h"
#include "play-sound.h"

int main() {
    generateRandomSound("noteA.wav");
    playSound("noteA.wav");
    generateRandomSound("noteB.wav");
    playSound("noteB.wav");
    generateRandomSound("noteC.wav");
    playSound("noteC.wav");

    generateRandomSound("hello.wav");
    playSound("hello.wav");
    return 0;
}
