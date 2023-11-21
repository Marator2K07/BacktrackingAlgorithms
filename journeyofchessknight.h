#ifndef JOURNEYOFCHESSKNIGHT_H
#define JOURNEYOFCHESSKNIGHT_H

#include <QObject>

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

    short beginX; // координата начала путешествия коня
    short beginY; // координата начала путешествия коня
    bool isDone; // могут ли быть осуществлены последующие ход/хода

    ///
    /// \brief next
    /// выбор следующего допустимого хода
    void next(int *nextX,
              int *nextY,
              int *k);

};

#endif // JOURNEYOFCHESSKNIGHT_H
