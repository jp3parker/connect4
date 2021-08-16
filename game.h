#ifndef GAME_INCLUDES
#define GAME_INCLUDES

#define HEIGHT 6
#define WIDTH 7

#include <iostream>

int makeMove(char[][WIDTH], char, int);
int available(char[][WIDTH], int);
bool checkWin(char[][WIDTH]);

#endif //GAME_INCLUDES
