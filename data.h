
#ifndef DATA_INCLUDES
#define DATA_INCLUDES

#include <opencv2/opencv.hpp>
#include "string.h"

#define HEIGHT 6
#define WIDTH 7

//I got pretty far into this project before realizing a struct with
//all my variables would be super useful.

struct GameData {
    char board[HEIGHT][WIDTH];
    int moveCount;//if even then player1 moves and vice versa
    std::string windowName;
    cv::Mat redPiece;
    cv::Mat fadedRedPiece;
    cv::Mat fadedYellowPiece;
    cv::Mat yellowPiece;
    cv::Mat connectBoard;
};

#endif //DATA_INCLUDES
