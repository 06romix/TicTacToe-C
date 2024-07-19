#include "field.c"
#include <stdlib.h>
#include <time.h>

int calculatePriority(int s, int symbol) {
    if (s == symbol) {
        return 2;
    } else if (s != Empty) {
        return -3;
    }
    return 0;
}

/*
 * X X X => -10
 * X X 0 => -10
 * 0 0 0 => -10
 * 0 0 X => -10
 *
 * X X - => 10
 *
 * 0 0 - => 8
 * - - X => 2
 * - - 0 => 1
 * - - - => 0
 * X - 0 => -1
 */
int getLinePriority(int s1, int s2, int s3, int symbol) {
    if (s1 != Empty && s2 != Empty && s3 != Empty) {
        return -10;
    }
    int priority = 0;
    priority += calculatePriority(s1, symbol);
    priority += calculatePriority(s2, symbol);
    priority += calculatePriority(s3, symbol);
    if (priority == 4) {
        return 10;
    }
    if (priority == -6) {
        return 8;
    }
    if (priority == -3) {
        return 1;
    }
    return priority;
}

int getRandomValue(int values[], int count) {
    if (count == 1) {
        return values[0];
    }
    srand(time(0));
    int randomIndex = rand() % count;
    return values[randomIndex];
}

int chooseBestLine(Cell field[9], int symbol) {
    int count[5] = {0, 0, 0, 0, 0};
    int sortedLines[5][8] = {0};
    int priority = 0;
    for (int i = 0; i < 8; i++) {
        priority = getLinePriority(
            field[combs[i][0]].symbol,
            field[combs[i][1]].symbol,
            field[combs[i][2]].symbol,
            symbol
        );
        switch (priority) {
            case 10:
                return i;
            case 8:
                sortedLines[0][count[0]] = i;
                count[0]++;
                break;
            case 2:
                sortedLines[1][count[1]] = i;
                count[1]++;
                break;
            case 1:
                sortedLines[2][count[2]] = i;
                count[2]++;
                break;
            case 0:
                sortedLines[3][count[3]] = i;
                count[3]++;
                break;
            case -1:
                sortedLines[4][count[4]] = i;
                count[4]++;
                break;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (count[i]) {
            return getRandomValue(sortedLines[i], count[i]);
        }
    }
    return -1;
}

void aiTurn(Cell field[9], int symbol) {
    int bestLine = chooseBestLine(field, symbol);
    if (bestLine != -1) {
        for (int i = 0; i < 3; i++) {
            if (field[combs[bestLine][i]].symbol == Empty) {
                field[combs[bestLine][i]].symbol = symbol;
                return;
            }
        }
    }
}
