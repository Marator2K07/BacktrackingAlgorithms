#include "eightqueensproblem.h"

EightQueensProblem::EightQueensProblem(QObject *parent)
    : QObject{parent}
{

}

bool EightQueensProblem::canBeDone(Chessboard *chessboard,
                                   short *rowIndex,
                                   short columnIndex)
{
    // подготовка
    bool *isDone = new bool{false};
    // условная операция УСТАНОВИТЬ ФЕРЗЯ
    x[columnIndex] = *rowIndex;
    a[*rowIndex] = false;
    b[columnIndex + (*rowIndex)] = false;
    c[columnIndex - (*rowIndex) + сhessboardSize - 1] = false;
    // а теперь ставим фигуру на доску
    chessboard->getCells()[columnIndex][*rowIndex];
    // тут должен быть метод, пытающийся найти следующее безопасное место
    //

    // если не получилось продвинуться то отменяем все свой/свои ход/ходы!
    if (!(*isDone)) {
        // условная операция УБРАТЬ ФЕРЗЯ
        x[columnIndex] = *rowIndex;
        a[*rowIndex] = true;
        b[columnIndex + (*rowIndex)] = true;
        c[columnIndex - (*rowIndex) + сhessboardSize - 1] = true;
        // убираем фигуру с доски
        chessboard->getCells()[columnIndex][*rowIndex];
    }
    // после использования, очищаем память, перед этим ее запоминая
    // после можно спокойно вернуть результат
    bool result{isDone};
    delete isDone;
    return result;
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
            c[columnIndex-(*rowIndex) + сhessboardSize - 1]) {
            break;
        }
    } while (*rowIndex != сhessboardSize);
    *endOfOptions = (*rowIndex == сhessboardSize);
}

void EightQueensProblem::first(bool *endOfOptions,
                               short *rowIndex,
                               short columnIndex)
{
    // подготовливаем поиск с первой позиции
    *endOfOptions = false;
    (*rowIndex) = -1;
    next(endOfOptions, rowIndex, columnIndex); // сам поиск
}
