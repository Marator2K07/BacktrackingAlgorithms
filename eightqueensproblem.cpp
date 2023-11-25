#include "eightqueensproblem.h"

EightQueensProblem::EightQueensProblem(QObject *parent)
    : QObject{parent}
{

}

Chessboard *EightQueensProblem::getChessboard() const
{
    return chessboard;
}

void EightQueensProblem::setChessboard(Chessboard *newChessboard)
{
    chessboard = newChessboard;
}

bool EightQueensProblem::canBeDone(short *rowIndex, short columnIndex)
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
    // теперь пошла вложенная часть с попыткой сделать следующий ход!
    tryFindNextPos(columnIndex, isDone);
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
    bool result{*isDone};
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

void EightQueensProblem::tryFindNextPos(short columnIndex, bool *isDone)
{
    // подготовка переменных для вызывающих методов
    bool *endOfOptions = new bool;
    short *rowIndex = new short;

    // пытаемся расставить все 8 фигур фигур по доске
    if (columnIndex < сhessboardSize) {
        // в приоритете всегда первый вариант
        first(endOfOptions, rowIndex, columnIndex);
        // пытаемся найти следующее доступное безопасное место
        while (!(*endOfOptions) &&
               !canBeDone(rowIndex, columnIndex)) {
            next(endOfOptions, rowIndex, columnIndex);
        }
        *isDone = !endOfOptions;
    } else {
        *isDone = true;
    }

    // чистим выделенную память
    delete endOfOptions;
    delete rowIndex;
}

bool EightQueensProblem::attemptToSolve()
{
    // подготовка для будущего расчета
    bool *isDone = new bool;

    // расчет начнем только если доска была выбрана и ее размер корректен
    if (chessboard != nullptr && chessboard->getSize() == сhessboardSize) {
        tryFindNextPos(0, isDone);
    } else {
        *isDone = false;
    }

    // чистим память, одновременно запоминая результат
    bool result{*isDone};
    delete isDone;
    return result;
}
