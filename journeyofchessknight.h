#ifndef JOURNEYOFCHESSKNIGHT_H
#define JOURNEYOFCHESSKNIGHT_H

#include <QObject>

#include "chessboard.h"

///
/// \brief The JourneyOfChessKnight class
/// Класс демонстрации одноименной задачи.
/// Условия данной задачи - попытаться обойти всю
/// шахматную доску
class JourneyOfChessKnight : public QObject
{
    Q_OBJECT
public:
    explicit JourneyOfChessKnight(QObject *parent = nullptr);

private:
    const short movesSize = 8;
    short *movesX; // вспомогательный массив ходов коня по оси Х
    short *movesY; // вспомогательный массив ходов коня по оси Y
    bool isDone; // могут ли быть осуществлены последующие ход/хода

    ///
    /// \brief canBeDone
    /// данным методом мы проверяем, возможна
    /// ли запись в следующую ячейку порядкового номера хода
    bool canBeDone(Chessboard *chessboard,
                   short currentX,
                   short currentY,
                   short i);
    ///
    /// \brief next
    /// выбор следующего допустимого хода
    void next(Chessboard *chessboard,
              short *thisX,
              short *thisY,
              short *nextX,
              short *nextY,
              short *k,
              bool *eos);
    ///
    /// \brief first
    /// порождение первого допустимого хода
    void first(Chessboard *chessboard,
               short *thisX,
               short *thisY,
               short *nextX,
               short *nextY,
               short *k,
               bool *eos);
    ///
    /// \brief tryNextMove
    /// метод говорит сам за себя - попытка сделать
    /// следующий ход, успешный он или нет, узнается в процессе
    void tryNextMove(Chessboard *chessboard,
                     short currentX,
                     short currentY,
                     short i);

public:
    ///
    /// \brief clear
    /// чистка ходов для определенной доски
    void clear(Chessboard *chessboard);
    ///
    /// \brief startTour
    /// метод запуска "путешествия" шахматного коня
    void startTour(Chessboard *chessboard,
                   short startX,
                   short startY);
};

#endif // JOURNEYOFCHESSKNIGHT_H
