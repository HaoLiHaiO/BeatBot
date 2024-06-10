#include "non-blocking-mode.h"
#include <unistd.h>
#include <fcntl.h>

void setNonBlockingMode(int enable) {
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    if (enable) {
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    } else {
        fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
    }
}