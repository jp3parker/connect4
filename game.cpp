
#include "game.h"

int makeMove(char board[][WIDTH], char color, int column) {
    int placed = -1;
    for (int i=HEIGHT-1; i>=0 and placed == -1; --i) {
        if (board[i][column-1]==' ') {
            board[i][column-1] = color;
            placed = i;
        }
    }
    return placed;
}

int available(char board[][WIDTH], int column) {
    int available = -1;
    for (int i=HEIGHT-1; i>=0 and available == -1; --i) {
        if (board[i][column-1]==' ') {
            available = i;
        }
    }
    return available;
}

//this code is long and inefficient -- should probably change it
bool checkWin(char board[][WIDTH]) {
    bool won = false;
    for (int i=0; i<WIDTH; ++i) {
        for (int j=HEIGHT-1; j>=0 and board[j][i] != ' ' and !won; --j) {
            char color = board[j][i];
            if ((j-3) >= 0) {
                if (board[j-1][i] == color and board[j-2][i] == color and board[j-3][i] == color) {
                    won = true;
                }
                if ((i-3) >= 0 and board[j-1][i-1] == color and board[j-2][i-2] == color and board[j-3][i-3] == color) {
                    won = true;
                }
            }
            if ((i+3) < WIDTH) {
                if (board[j][i+1] == color and board[j][i+2] == color and board[j][i+3] == color) {
                    won = true;
                }
                if ((j-3) >= 0 and board[j-1][i+1] == color and board[j-2][i+2] == color and board[j-3][i+3] == color) {
                    won = true;
                }
            }
        }
    }
    return won;
}
