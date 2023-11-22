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
    bool eos; // условие, что ходов больше нет

    short nextX; // следующая координата путешествия коня
    short nextY; // следующая координата путешествия коня

    bool isDone; // могут ли быть осуществлены последующие ход/хода
    short k; // вспомогательный индекс хода
    short i; // индекс текущего хода

    ///
    /// \brief canBeDone
    /// данным методом мы проверяем, возможна
    /// ли запись в следующую ячейку порядкового номера хода
    bool canBeDone(Chessboard *chessboard,
                   short currentX,
                   short currentY);
    ///
    /// \brief next
    /// выбор следующего допустимого хода
    void next(Chessboard *chessboard,
              short currentX,
              short currentY);
    ///
    /// \brief first
    /// порождение первого допустимого хода
    void first(Chessboard *chessboard,
               short currentX,
               short currentY);
    ///
    /// \brief tryNextMove
    /// метод говорит сам за себя - попытка сделать
    /// следующий ход, успешный он или нет, узнается в процессе
    void tryNextMove(Chessboard *chessboard,
                     short currentX,
                     short currentY);

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
