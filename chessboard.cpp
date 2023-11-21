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
}

int **Chessboard::getCells()
{
    return cells;
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
