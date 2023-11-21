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

    short beginX; // координата начала путешествия коня
    short beginY; // координата начала путешествия коня
    bool isDone; // могут ли быть осуществлены последующие ход/хода
    short k; // вспомогательный индекс хода

    ///
    /// \brief next
    /// выбор следующего допустимого хода
    void next(Chessboard *chessboard,
              short *nextX,
              short *nextY);
    ///
    /// \brief first
    /// порождение первого допустимого хода
    void first(Chessboard *chessboard,
               short *nextX,
               short *nextY);

};

#endif // JOURNEYOFCHESSKNIGHT_H
