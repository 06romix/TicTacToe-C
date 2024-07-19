#include "field.c"
#include <stdio.h>
#include "console.c"
#include "symbols.c"

enum GameStatus {
    InProgress = 0,
    xWin = X,
    ZeroWin = Zero,
    Draw = 3,
};

int chooseSymbol() {
    int playerSymbol = 0;
    printf("Choose symbol:\n1 - X\n2 - 0\n");
    while (playerSymbol != Zero && playerSymbol != X) {
        scanf("%d", &playerSymbol);
        clearLines(1);
    }
    clearLines(4);
    return playerSymbol;
}

int getGameStatus(Cell field[9]) {
    for (int i = 0; i < 8; i++) {
        if (field[combs[i][0]].symbol == 0) {
            continue;
        }
        if (field[combs[i][0]].symbol == field[combs[i][1]].symbol
            && field[combs[i][1]].symbol == field[combs[i][2]].symbol
        ) {
            return field[combs[i][0]].symbol;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (field[i].symbol == 0) {
            return InProgress;
        }
    }
    return Draw;
}

void playerTurn(Cell field[9], int symbol) {
    printf("Select position by entering numbers within 1-9 range\n");
    int position = 10;
    while (!isValidPosition(field, position)) {
        scanf("%d", &position);
        clearLines(1);
    }
    clearLines(1);
    field[position - 1].symbol = symbol;
}

void printResult(int gameStatus, int playerSymbol) {
    if (gameStatus == Draw) {
        printf("Draw!\n");
        return;
    }
    if (gameStatus == playerSymbol) {
        printf("Victory!\n");
        return;
    }
    printf("Defeat!\n");
}
