#ifndef STABLEMARRIAGES_H
#define STABLEMARRIAGES_H

#include "man.h"
#include "women.h"

#include <QObject>

///
/// \brief The StableMarriages class
/// класс пытается решить задачу о стабильных браках, суть которой,
/// найти такие пары людей, где партнеры максимально подходят друг
/// другу (условно это можно выразить какой-то оценкой в виде числа)
class StableMarriages : public QObject
{
    Q_OBJECT
public:
    explicit StableMarriages(short numberOfPairs, QObject *parent = nullptr);

private:
    short numberOfPairs; // количество пар браков
    QList<Man *> mans; // список мужчин, доступных для брака
    QList<Women *> womens; // список женщин, доступных для брака
    QHash<Women *, bool> single; // словарь с информацией о замужности
    QHash<Man *, Women *> couples; // словарь с уже обрученными парочками

    ///
    /// \brief isStable
    /// оценка стабильности брака (есть ли партнеры лучше текущих)
    bool isStable(Man *man, Women *women);
    ///
    /// \brief tryFindCouple
    /// попытка найти себе пару, отталкиваться будем от мужчин,
    /// но по сути разницы никакой нет
    void tryFindCouple(short manIndex);

public:
    ///
    /// \brief printInfo
    /// вывод всех текущих рейтингов-оценок
    void printInfo();

};

#endif // STABLEMARRIAGES_H
