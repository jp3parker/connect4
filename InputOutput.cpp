#include "InputOutput.h"

//the hardest part of this project was understanding how to use this function.
//especially the "void* userdata" parameter.
void CallBackFunc(int event, int x, int y, int flags, void* userdata) {
    GameData* carrier = static_cast<GameData *>(userdata);
    if (event == cv::EVENT_LBUTTONDOWN) {
        int row = makeMove(carrier->board, (carrier->moveCount%2)?'O':'X', (x/SMALLIMAGESIZE)+1);
        if (row != -1) {
            newImage(row, (x/SMALLIMAGESIZE), carrier);
            if (checkWin(carrier->board)) {//if a player has won, stop CallBackFunc, back to main
                cv::setMouseCallback(carrier->windowName, NULL, NULL);
                return;
            }
        }
    }
    else if (event == cv::EVENT_MOUSEMOVE) {
        int row = available(carrier->board, (x/SMALLIMAGESIZE)+1);
        if (row != -1) {
            fadedImage(row, x/SMALLIMAGESIZE, carrier);
        }
    }
}

//this code is called when the mouse moves.
//it copies the current connectboard image and
//adds a faded yellow/red piece in the column where the mouse is.
void fadedImage(int row, int column, GameData* carrier) {
    cv::Mat nextPiece;
    if (carrier->moveCount%2) {
        nextPiece = carrier->fadedRedPiece;
    }
    else {
        nextPiece = carrier->fadedYellowPiece;
    }
    cv::Mat newBoard = carrier->connectBoard.clone();
    cv::Rect roi = cv::Rect(column*SMALLIMAGESIZE, row*SMALLIMAGESIZE, nextPiece.cols, nextPiece.rows);
    cv::Mat subView = newBoard(roi);
    nextPiece.copyTo(subView);
    cv::imshow(carrier->windowName, newBoard);
    return;
}

//this code is called when the mouse clicks on a column that is not full.
//it adds a red/yellow piece to the column that the mouse clicked.
void newImage(int row, int column, GameData* carrier) {
    cv::Mat nextPiece;
    if (carrier->moveCount%2) {
        nextPiece = carrier->redPiece;
    }
    else {
        nextPiece = carrier->yellowPiece;
    }
    cv::Rect roi = cv::Rect(column*SMALLIMAGESIZE, row*SMALLIMAGESIZE, nextPiece.cols, nextPiece.rows);
    cv::Mat subView = carrier->connectBoard(roi);
    nextPiece.copyTo(subView);
    cv::imshow(carrier->windowName, carrier->connectBoard);
    ++(carrier->moveCount);
    return;
}
