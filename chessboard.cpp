#include "chessboard.h"

Chessboard::Chessboard(short size, QObject *parent)
    : QObject{parent}
{
    this->size = size;
    cells = new int*[size];
    for (int i = 0; i < size; i++)
    {
        cells[i] = new int[size];
        // сразу инициализируем данный массив нулями
        for (int k = 0; k < size; k++)
        {
            cells[i][k] = 0;
        }
    }

    currentCellX = 0;
    currentCellY = 0;
    isFilled = false;
}

short Chessboard::getCurrentCellX() const
{
    return currentCellX;
}

void Chessboard::setCurrentCellX(short newXIndex)
{
    currentCellX = newXIndex;
}

short Chessboard::getCurrentCellY() const
{
    return currentCellY;
}

void Chessboard::setCurrentCellY(short newYIndex)
{
    currentCellY = newYIndex;
}

int **Chessboard::getCells()
{
    return cells;
}

bool Chessboard::getIsFilled() const
{
    return isFilled;
}

void Chessboard::setIsFilled(bool newIsFilled)
{
    isFilled = newIsFilled;
}

void Chessboard::print()
{
    QTextStream out(stdout);

    for (int i = 0; i < size; i++)
    {
        out << '|';
        for (int k = 0; k < size; k++)
        {
            if (QString::number(cells[i][k]).length() <= 1) {
                out << ' ';
            }
            out << cells[i][k] << '|';
        }
        out << Qt::endl;
    }
}

short Chessboard::getSize() const
{
    return size;
}
