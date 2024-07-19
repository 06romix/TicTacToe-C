#include <stdio.h>
#include "console.c"
#include "symbols.c"

#ifndef TIC_TAC_TOE_FIELD_H
#define TIC_TAC_TOE_FIELD_H
typedef struct {
    int symbol;
} Cell;

void setEmptyField(Cell field[9]) {
    for (int i = 0; i < 9; i++) {
        field[i].symbol = Empty;
    }
}

void renderField(Cell field[9]) {
    printf("%c %c %c\n", SMap[field[6].symbol], SMap[field[7].symbol], SMap[field[8].symbol]);
    printf("%c %c %c\n", SMap[field[3].symbol], SMap[field[4].symbol], SMap[field[5].symbol]);
    printf("%c %c %c\n", SMap[field[0].symbol], SMap[field[1].symbol], SMap[field[2].symbol]);
    printf("\n");
}

void reRenderField(Cell field[9]) {
    clearLines(4);
    renderField(field);
}

int isValidPosition(Cell field[9], int position) {
    if (position > 9 || position < 1) {
        return 0;
    }
    return field[position - 1].symbol == 0;
}

#endif //TIC_TAC_TOE_FIELD_H
