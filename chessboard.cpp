#include "chessboard.h"

Chessboard::Chessboard(short size, QObject *parent)
    : QObject{parent}
{
    this->size = size;
    cells = new int*[size];
    for (int i = 0; i < size; i++)
    {
        cells[i] = new int[size];
    }

    currentCellX = 0;
    currentCellY = 0;
    isFilled = false;
}
