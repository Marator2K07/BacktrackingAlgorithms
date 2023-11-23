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
                                     short currentY,
                                     short i)
{
    // сначала мы сразу заполняем ячейку номером сделанного
    // хода, и в случае неудачи, можем даже "откатить операцию"
    chessboard->getCells()[currentX][currentY] = i;
    chessboard->print();
    tryNextMove(chessboard, currentX, currentY, i);
    if (!isDone) {
        chessboard->getCells()[currentX][currentY] = 0;
    }    
    return isDone;
}

void JourneyOfChessKnight::next(Chessboard *chessboard,
                                short *thisX,
                                short *thisY,
                                short *nextX,
                                short *nextY,
                                short *k,
                                bool *eos)
{
    // пока координаты следующего хода находятся в пределах
    // доски и сами варианты ходов не перебраны - все впорядке
    do {
        (*k)++;
        if (*k < 8) {
            *nextX = *thisX + movesX[*k];
            *nextY = *thisY + movesY[*k];
        }
        // в случае успешности выбора координат - останавливаем цикл
        if ((0 <= *nextX) &&
            (*nextX < chessboard->getSize()) &&
            (0 <= *nextY) &&
            (*nextY < chessboard->getSize()) &&
            (chessboard->getCells()[*nextX][*nextY]) == 0) {
            break;
        }
    } while (*k != 8);
    *eos = (*k == 8);
}


void JourneyOfChessKnight::first(Chessboard *chessboard,
                                 short *thisX,
                                 short *thisY,
                                 short *nextX,
                                 short *nextY,
                                 short *k,
                                 bool *eos)
{
    *eos = false;
    *k = -1; // таким образом косвенно выбираем ход
    next(chessboard, thisX, thisY, nextX, nextY, k, eos);
}

void JourneyOfChessKnight::tryNextMove(Chessboard *chessboard,
                                       short currentX,
                                       short currentY,
                                       short i)
{
    // подготовка
    short *thisX = new short{currentX};
    short *thisY = new short{currentY};
    short *nextX = new short; // координата следующего потенциального хода
    short *nextY = new short; // координата следующего потенциального хода
    short *k = new short; // вспомогательный индекс хода
    bool *eos = new bool; // условие, что ходов больше нет

    // пытаемся сделать ход пока есть место на доске
    if (i < chessboard->getSize() * chessboard->getSize() - 1) {
        first(chessboard, thisX, thisY, nextX, nextY, k, eos); // в приоритете всегда первый вариант хода коня
        // пытаемся найти доступный следующий ход
        while (!(*eos) && !canBeDone(chessboard, *nextX, *nextY, i+1)) {
            next(chessboard, thisX, thisY, nextX, nextY, k, eos);
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

void JourneyOfChessKnight::startTour(Chessboard *chessboard,
                                     short startX,
                                     short startY)
{
    clear(chessboard);
    // cразу заполняем значение стартовой ячейки
    // пытаемся сделать следующий ПЕРВЫЙ ход
    chessboard->getCells()[startX][startY] = 1;
    tryNextMove(chessboard, startX, startY, 1);
}
