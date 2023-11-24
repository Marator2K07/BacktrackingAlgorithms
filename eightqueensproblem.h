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
    short correctChessboardSize = 8;
    static short const arrSize = 8;
    int x[arrSize]{-1}; // положение ферзей в столбцах
    bool a[arrSize]{true}; // отсутствие ферзей в рядах
    bool b[arrSize*2-1]{true}; // отсутствие ферзей в / - диагоналях
    bool c[arrSize*2-1]{true}; // отсутствие ферзей в \ - диагоналях

    ///
    /// \brief canBeDone
    /// проверяем, возможно ли поставить королеву
    /// в следующую безопасную от всех позицию
    bool canBeDone(Chessboard *chessboard,
                   short *rowIndex,
                   short columnIndex);
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
};

#endif // EIGHTQUEENSPROBLEM_H
