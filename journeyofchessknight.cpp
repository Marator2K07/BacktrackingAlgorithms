#include "journeyofchessknight.h"

JourneyOfChessKnight::JourneyOfChessKnight(QObject *parent)
    : QObject{parent}
{
    // инициализация массивов ходов шахматного коня
    movesX = new short[movesSize] {2, 1, -1, -2, -2, -1, 1, 2};
    movesY = new short[movesSize] {1, 2, 2, 1, -1, -2, -2, -1};
}

bool JourneyOfChessKnight::canBeDone(Chessboard *chessboard,
                                     short currentX,
                                     short currentY)
{
    // сначала мы сразу заполняем ячейку номером сделанного
    // хода, и в случае неудачи, можем даже "откатить операцию"
    chessboard->getCells()[nextX][nextY] = i;
    tryNextMove(chessboard, currentX, currentY);
    if (!isDone) {
        chessboard->getCells()[nextX][nextY] = 0;
    }
    return isDone;
}

void JourneyOfChessKnight::next(Chessboard *chessboard,
                                short currentX,
                                short currentY)
{
    // пока координаты следующего хода находятся в пределах
    // доски и сами варианты ходов не перебраны - все впорядке
    do {
        k++;
        if (k < 8) {
            nextX = currentX + movesX[k];
            nextY = currentY + movesY[k];
        }
    } while (k != 8 && ((0 <= nextX) &&
                        (nextX < chessboard->getSize()) &&
                        (0 <= nextY) &&
                        (nextY < chessboard->getSize()) &&
                        chessboard->getCells()[nextX][nextY] == 0));
    eos = (k == 8);
}


void JourneyOfChessKnight::first(Chessboard *chessboard,
                                 short currentX,
                                 short currentY)
{
    eos = false;
    k = -1; // таким образом косвенно выбираем ход
    next(chessboard, currentX, currentY);
}

void JourneyOfChessKnight::tryNextMove(Chessboard *chessboard,
                                       short currentX,
                                       short currentY)
{
    // пытаемся сделать ход пока есть место на доске
    if (i < chessboard->getSize()*
            chessboard->getSize()) {
        first(chessboard, currentX, currentY); // в приоритете всегда первый вариант хода коня
        i++;
        // пытаемся найти доступный следующий ход
        while (!eos && !canBeDone(chessboard, currentX, currentY)) {
            next(chessboard, currentX, currentY);
        }
        isDone = !eos;
    } else {
        isDone = true;
    }
}

void JourneyOfChessKnight::clear(Chessboard *chessboard)
{
    chessboard->clear();
}
