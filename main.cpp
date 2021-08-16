
#include "main.h"


int main() {
    GameData carrier;
    for (int i=0; i<HEIGHT; ++i) {
        for (int j=0; j<WIDTH; ++j) {
            carrier.board[i][j] = ' ';
        }
    }
    carrier.moveCount = 0;
    carrier.windowName = "Connect-4";
    carrier.redPiece = imread("./images/redpiece.jpg", cv::IMREAD_COLOR);
    carrier.yellowPiece = imread("./images/yellowpiece.jpg", cv::IMREAD_COLOR);
    carrier.fadedRedPiece = imread("./images/fadedredpiece.jpg", cv::IMREAD_COLOR);
    carrier.fadedYellowPiece = imread("./images/fadedyellowpiece.jpg", cv::IMREAD_COLOR);
    carrier.connectBoard = imread("./images/connectboard.jpg", cv::IMREAD_COLOR);
    if (carrier.redPiece.empty() or carrier.yellowPiece.empty() or carrier.connectBoard.empty()
        or carrier.fadedRedPiece.empty() or carrier.fadedYellowPiece.empty()) {
        std::cout << "error loading image(s)" << std::endl;
        return 1;
    }
    cv::namedWindow(carrier.windowName, cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback(carrier.windowName, CallBackFunc, &carrier);
    cv::imshow(carrier.windowName, carrier.connectBoard);
    cv::waitKey(0);
    
    return 0;
}
