#ifndef EIGHTQUEENSPROBLEM_H
#define EIGHTQUEENSPROBLEM_H

#include <QObject>

#include "chessboard.h"

///
/// \brief The EightQueensProblem class
/// Задача о восьми ферзях: суть в том, чтобы
/// ни одна из королев не могла побить любую другую.
/// То есть - все они должны быть расставлены по шахматной
/// доске безопасно относительно друг друга
class EightQueensProblem : public QObject
{
    Q_OBJECT
public:
    explicit EightQueensProblem(QObject *parent = nullptr);

private:
    static short const сhessboardSize = 8;
    int x[сhessboardSize]; // положение ферзей в столбцах
    bool a[сhessboardSize]; // отсутствие ферзей в рядах
    bool b[сhessboardSize*2-1]; // отсутствие ферзей в / - диагоналях
    bool c[сhessboardSize*2-1]; // отсутствие ферзей в \ - диагоналях
    Chessboard *chessboard = nullptr; // текущая шахматная доска
    bool isDone; // могут ли быть осуществлены последующие ход/хода

    ///
    /// \brief reset
    /// сброс всех полей к начальным значениям для
    /// будущих расчетов
    void reset();
    ///
    /// \brief canBeDone
    /// ставим фигуру на найденную безопасную позицию
    /// и ищем следующую(позицию), в случае неудачи -
    /// откатываемся назад
    bool canBeDone(short *rowIndex, short columnIndex);
    ///
    /// \brief next
    /// выбор следующей безопасной позиции для ферзя
    void next(bool *endOfOptions,
              short *rowIndex,
              short columnIndex);
    ///
    /// \brief first
    /// порождение первой возможной безопасной позиции для ферзя
    void first(bool *endOfOptions,
               short *rowIndex,
               short columnIndex);
    ///
    /// \brief tryFindNextPos
    /// попытка найти следующую безопасную позицию для королевы,
    /// успешная она будет или нет, узнается в процессе
    /// (если попытка успешна, то позиция остается занята)
    void tryFindNextPos(short columnIndex);

public:
    ///
    /// \brief attemptToSolve
    /// попытка решить поставленную задачу, описанную в классе
    /// в случае удачи - возвращается истина, иначе - ложь
    bool attemptToSolve();

    Chessboard *getChessboard() const;
    void setChessboard(Chessboard *newChessboard);
};

#endif // EIGHTQUEENSPROBLEM_H
