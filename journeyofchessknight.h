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
    explicit JourneyOfChessKnight(int beginX,
                                  int beginY,
                                  QObject *parent = nullptr);

private:
    const short movesSize = 8;
    short *movesX; // вспомогательный массив ходов коня по оси Х
    short *movesY; // вспомогательный массив ходов коня по оси Y
    bool eos; // условие, что ходов больше нет

    short beginX; // начальная координата путешествия
    short beginY; // начальная координата путешествия
    short nextX; // следующая координата путешествия коня
    short nextY; // следующая координата путешествия коня

    bool isDone; // могут ли быть осуществлены последующие ход/хода
    short k; // вспомогательный индекс хода
    short i; // индекс текущего хода

    ///
    /// \brief canBeDone
    /// данным методом мы проверяем, возможна
    /// ли запись в следующую ячейку порядкового номера хода
    bool canBeDone(Chessboard *chessboard);
    ///
    /// \brief next
    /// выбор следующего допустимого хода
    void next(Chessboard *chessboard);
    ///
    /// \brief first
    /// порождение первого допустимого хода
    void first(Chessboard *chessboard);
    ///
    /// \brief tryNextMove
    /// метод говорит сам за себя - попытка сделать
    /// следующий ход, успешный он или нет, узнается в процессе
    void tryNextMove(Chessboard *chessboard);

public:
    ///
    /// \brief clear
    /// чистка ходов для определенной доски
    void clear(Chessboard *chessboard);

};

#endif // JOURNEYOFCHESSKNIGHT_H
