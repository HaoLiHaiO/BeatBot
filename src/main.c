#include "generate-sound.h"
#include "play-sound.h"

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
