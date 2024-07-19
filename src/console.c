#ifndef TIC_TAC_TOE_CONSOLE_H
#define TIC_TAC_TOE_CONSOLE_H

#include <stdio.h>

void clearLines(int number) {
    if (number < 1) {
        return;
    }
    for (int i = 0; i < number; i++) {
        printf("\033[1A");
        printf("\033[2K");
    }
    printf("\r");
}

#endif //TIC_TAC_TOE_CONSOLE_H
