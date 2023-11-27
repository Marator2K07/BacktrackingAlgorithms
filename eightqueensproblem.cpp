#include "eightqueensproblem.h"

EightQueensProblem::EightQueensProblem(QObject *parent)
    : QObject{parent}
{
    reset();
    isDone = false;
    solutionsCount = 0;
}

void EightQueensProblem::reset()
{
    for (int i = 0; i < сhessboardSize; ++i) {
        a[i] = true;
    }
    for (int i = 0; i < сhessboardSize * 2 - 1; ++i) {
        b[i] = true;
        c[i] = true;
    }
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
    // условная операция УСТАНОВИТЬ ФЕРЗЯ
    a[*rowIndex] = false;
    b[columnIndex + (*rowIndex)] = false;
    c[columnIndex - (*rowIndex) + сhessboardSize - 1] = false;
    // а теперь ставим фигуру на доску
    chessboard->getCells()[*rowIndex][columnIndex] = columnIndex + 1;
    chessboard->print(); // после "шага вперед" печатаем текущий результат
    // теперь пошла вложенная часть с попыткой сделать следующий ход!
    tryFindNextPos(columnIndex + 1);
    // если не получилось продвинуться то отменяем все свой/свои ход/ходы!
    if (!isDone) {
        // условная операция УБРАТЬ ФЕРЗЯ
        a[*rowIndex] = true;
        b[columnIndex + (*rowIndex)] = true;
        c[columnIndex - (*rowIndex) + сhessboardSize - 1] = true;
        // убираем фигуру с доски
        chessboard->getCells()[*rowIndex][columnIndex] = 0;
        chessboard->print(); // после "шага назад" печатаем текущий результат
    }

    return isDone;
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

void EightQueensProblem::tryFindNextPos(short columnIndex)
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
        isDone = !(*endOfOptions);
    } else {
        isDone = true;
    }

    // чистим выделенную память
    delete endOfOptions;
    delete rowIndex;
}

void EightQueensProblem::tryFindNextPosSimple(short columnIndex)
{
    // пытаемся поставить фигуру/фигуры
    if (columnIndex < сhessboardSize) {
        for (int rowIndex = 0; rowIndex < сhessboardSize; ++rowIndex) {
            // если нашли безопасное место место для королевы, то
            if (a[rowIndex] &&
                b[columnIndex+(rowIndex)] &&
                c[columnIndex-(rowIndex) + сhessboardSize - 1]) {
                // ставим флаги и
                a[rowIndex] = false;
                b[columnIndex + (rowIndex)] = false;
                c[columnIndex - (rowIndex) + сhessboardSize - 1] = false;
                // фигуру на доску,
                chessboard->getCells()[rowIndex][columnIndex] = columnIndex + 1;
                // запускаем слудующий ход и
                tryFindNextPosSimple(columnIndex + 1);
                // после нахождения решения - убираем флаги
                a[rowIndex] = true;
                b[columnIndex + (rowIndex)] = true;
                c[columnIndex - (rowIndex) + сhessboardSize - 1] = true;
            }
        }
    } else {
        qInfo() << QString("Answer №[%1]").arg(solutionsCount);
        chessboard->print();        
        solutionsCount++;
    }
}

bool EightQueensProblem::attemptToSolve()
{
    // расчет начнем только если доска была выбрана и ее размер корректен
    if (chessboard != nullptr && chessboard->getSize() == сhessboardSize) {
        chessboard->clear();
        tryFindNextPos(0);
    } else {
        isDone = false;
    }

    return isDone;
}

short EightQueensProblem::allSolutions()
{
    reset();
    chessboard->clear();
    solutionsCount = 0;
    tryFindNextPosSimple(0);

    return solutionsCount;
}
