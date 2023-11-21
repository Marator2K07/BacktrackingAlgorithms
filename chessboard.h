#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>

///
/// \brief The Chessboard class
/// Условная шахматная доска квадратного заданного размера
class Chessboard : public QObject
{
    Q_OBJECT
public:
    explicit Chessboard(short size, QObject *parent = nullptr);

    short getCurrentCellX() const;
    void setCurrentCellX(short newXIndex);
    short getCurrentCellY() const;
    void setCurrentCellY(short newYIndex);
    int **getCells();
    bool getIsFilled() const;
    void setIsFilled(bool newIsFilled);

private:
    short size;
    short currentCellX;
    short currentCellY;
    int** cells; // ячейки доски под значения
    bool isFilled; // все ли ячейки доски были задействованы

signals:

};

#endif // CHESSBOARD_H
