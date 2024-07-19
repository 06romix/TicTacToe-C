#include <stdio.h>
#include "src/ai.c"
#include "src/game.c"

int main() {
    printf("Welcome in Tic-Tac-Toe!\n");
    int playerSymbol = chooseSymbol();
    int aiSymbol = (playerSymbol == Zero) ? X : Zero;
    Cell field[9];
    setEmptyField(field);
    int currentTurnSymbol = X;

    renderField(field);
    int gameStatus;
    while (1) {
        gameStatus = getGameStatus(field);
        if (gameStatus != InProgress) {
            break;
        }
        if (playerSymbol == currentTurnSymbol) {
            playerTurn(field, playerSymbol);
            currentTurnSymbol = aiSymbol;
        } else {
            aiTurn(field, aiSymbol);
            currentTurnSymbol = playerSymbol;
        }
        reRenderField(field);
    }
    printResult(gameStatus, playerSymbol);
    return 0;
}
