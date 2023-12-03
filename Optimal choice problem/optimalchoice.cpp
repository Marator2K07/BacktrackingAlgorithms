#include "optimalchoice.h"

OptimalChoice::OptimalChoice(QObject *parent) :
    QObject{parent},
    limitOfWeight{500},
    limitOfValue{1000},
    currentObjectsWeight{0},
    currentObjectsValue{0},
    optimalObjectsValue{0}
{
}

OptimalChoice::OptimalChoice(int limitOfWeight,
                             int totalValue,
                             QObject *parent) :
    QObject{parent},
    limitOfWeight{limitOfWeight},
    limitOfValue{totalValue},
    currentObjectsWeight{0},
    currentObjectsValue{0},
    optimalObjectsValue{0}
{
}

int OptimalChoice::getLimitOfWeight() const
{
    return limitOfWeight;
}

void OptimalChoice::setLimitOfWeight(int newLimitOfWeight)
{
    limitOfWeight = newLimitOfWeight;
}

int OptimalChoice::getLimitOfValue() const
{
    return limitOfValue;
}

void OptimalChoice::setLimitOfValue(int newLimitOfValue)
{
    limitOfValue = newLimitOfValue;
}

QSet<SomeObject *> OptimalChoice::selection(QList<SomeObject *> objects)
{
    // подготовка
    selectedCurrentObjects.clear();
    selectedOptimalObjects.clear();
    currentObjectsWeight = 0;
    currentObjectsValue = 0;
    optimalObjectsValue = 0;

    // начинаем собирать набор
    tryJoin(0, objects);

    return selectedOptimalObjects;
}

void OptimalChoice::tryJoin(int objectIndex, QList<SomeObject *> objects)
{

}
