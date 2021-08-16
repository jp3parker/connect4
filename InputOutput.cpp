#include "InputOutput.h"


void CallBackFunc(int event, int x, int y, int flags, void* userdata) {
    GameData* carrier = static_cast<GameData *>(userdata);
    if (event == cv::EVENT_LBUTTONDOWN) {
        int row = makeMove(carrier->board, (carrier->moveCount%2)?'O':'X', (x/130)+1);
        if (row != -1) {
            newImage(row, (x/130), carrier);
            if (checkWin(carrier->board)) {
                cv::setMouseCallback(carrier->windowName, NULL, NULL);
                return;
            }
        }
    }
    else if (event == cv::EVENT_MOUSEMOVE) {
        int row = available(carrier->board, (x/130)+1);
        if (row != -1) {
            fadedImage(row, x/130, carrier);
        }
    }
}

void fadedImage(int row, int column, GameData* carrier) {
    cv::Mat nextPiece;
    if (carrier->moveCount%2) {
        nextPiece = carrier->fadedRedPiece;
    }
    else {
        nextPiece = carrier->fadedYellowPiece;
    }
    cv::Mat newBoard = carrier->connectBoard.clone();
    cv::Rect roi = cv::Rect(column*130, row*130, nextPiece.cols, nextPiece.rows);
    cv::Mat subView = newBoard(roi);
    nextPiece.copyTo(subView);
    cv::imshow(carrier->windowName, newBoard);
    return;
}

void newImage(int row, int column, GameData* carrier) {
    cv::Mat nextPiece;
    if (carrier->moveCount%2) {
        nextPiece = carrier->redPiece;
    }
    else {
        nextPiece = carrier->yellowPiece;
    }
    cv::Rect roi = cv::Rect(column*130, row*130, nextPiece.cols, nextPiece.rows);
    cv::Mat subView = carrier->connectBoard(roi);
    nextPiece.copyTo(subView);
    cv::imshow(carrier->windowName, carrier->connectBoard);
    ++(carrier->moveCount);
    return;
}
