#include "journeyofchessknight.h"

JourneyOfChessKnight::JourneyOfChessKnight(int beginX,
                                           int beginY,
                                           QObject *parent)
    : QObject{parent}
{
    // инициализация массивов ходов шахматного коня
    movesX = new short[movesSize] {2, 1, -1, -2, -2, -1, 1, 2};
    movesY = new short[movesSize] {1, 2, 2, 1, -1, -2, -2, -1};

    this->beginX = beginX;
    this->beginY = beginY;
}

void JourneyOfChessKnight::next(Chessboard *chessboard,
                                short *nextX,
                                short *nextY)
{
    // пока координаты следующего хода находятся в пределах
    // доски и сами варианты ходов не перебраны - все впорядке
    do {
        k++;
        if (k < 8) {
            *nextX = beginX + movesX[k];
            *nextY = beginY + movesY[k];
        }
    } while (k != 8 && ((0 <= *nextX) &&
                        (*nextX < chessboard->getSize()) &&
                        (0 <= *nextY) &&
                        (*nextY < chessboard->getSize()) &&
                        chessboard->getCells()[*nextX][*nextY] == 0));
    eos = (k == 8);
}

void JourneyOfChessKnight::first(Chessboard *chessboard,
                                 short *nextX,
                                 short *nextY)
{
    eos = false;
    k = -1; // таким образом косвенно выбираем ход
    next(chessboard, nextX, nextY);
}

void JourneyOfChessKnight::clear(Chessboard *chessboard)
{
    chessboard->clear();
}
