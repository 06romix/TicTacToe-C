#ifndef TIC_TAC_TOE_SYMBOLS
#define TIC_TAC_TOE_SYMBOLS

enum Symbols {
    Zero = 2,
    X = 1,
    Empty = 0
};

char SMap[3] = {'-', 'X', '0'};


int combs[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {6, 4, 2},
};

#endif //TIC_TAC_TOE_SYMBOLS
