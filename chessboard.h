#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>
#include <QDebug>
#include <QTextStream>

///
/// \brief The Chessboard class
/// Условная шахматная доска квадратного заданного размера
class Chessboard : public QObject
{
    Q_OBJECT
public:
    explicit Chessboard(short size, QObject *parent = nullptr);

    short getSize() const;
    short getCurrentCellX() const;
    void setCurrentCellX(short newXIndex);
    short getCurrentCellY() const;
    void setCurrentCellY(short newYIndex);
    int **getCells();
    bool getIsFilled() const;
    void setIsFilled(bool newIsFilled);

public:
    ///
    /// \brief print
    /// метод печати текущего состояния доски
    /// (значений ее ячеек) в консоли
    void print();

private:
    short size;
    int** cells; // ячейки доски под значения

signals:

};

#endif // CHESSBOARD_H
