#include "eightqueensproblem.h"

EightQueensProblem::EightQueensProblem(QObject *parent)
    : QObject{parent}
{

}

void EightQueensProblem::next(bool *endOfOptions,
                              short *rowIndex,
                              short columnIndex)
{
    // поиск безопасной позиции
    do {
        (*rowIndex)++;
        // если нашли ее, то останавливаемся
        if (a[*rowIndex] &&
            b[columnIndex+(*rowIndex)] &&
            c[columnIndex-(*rowIndex) + correctChessboardSize - 1]) {
            break;
        }
    } while (*rowIndex != correctChessboardSize);
    *endOfOptions = (*rowIndex == correctChessboardSize);
}
