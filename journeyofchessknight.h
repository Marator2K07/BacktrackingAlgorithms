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

signals:

};

#endif // JOURNEYOFCHESSKNIGHT_H
