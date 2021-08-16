
#ifndef DATA_INCLUDES
#define DATA_INCLUDES

#include <opencv2/opencv.hpp>
#include "string.h"

#define HEIGHT 6
#define WIDTH 7

struct GameData {
    char board[HEIGHT][WIDTH];
    int moveCount;
    std::string windowName;
    cv::Mat redPiece;
    cv::Mat fadedRedPiece;
    cv::Mat fadedYellowPiece;
    cv::Mat yellowPiece;
    cv::Mat connectBoard;
};

#endif //DATA_INCLUDES
