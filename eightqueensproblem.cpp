#include "eightqueensproblem.h"

EightQueensProblem::EightQueensProblem(QObject *parent)
    : QObject{parent}
{

}

void EightQueensProblem::next(bool *endOfOptions,
                              short *j,
                              short i)
{
    // поиск безопасной позиции
    do {
        (*j)++;
        // если нашли ее, то останавливаемся
        if (a[*j] && b[i+(*j)] && c[i-(*j) + correctChessboardSize - 1]) {
            break;
        }
    } while (*j != correctChessboardSize);
    *endOfOptions = (*j == correctChessboardSize);
}
