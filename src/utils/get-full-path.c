#include "get-full-path.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h>

void getFullPath(const char* relativePath, char* fullPath, size_t size) {
    if (getcwd(fullPath, size) != NULL) {
        strncat(fullPath, relativePath, size - strlen(fullPath) - 1);
    } else {
        perror("getcwd() error");
    }
}
