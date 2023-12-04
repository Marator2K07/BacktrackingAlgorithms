#include "optimalchoice.h"

OptimalChoice::OptimalChoice(QObject *parent) :
    QObject{parent},
    limitOfWeight{500},
    limitOfValue{1000},
    optimalObjectsValue{0}
{
}

OptimalChoice::OptimalChoice(int limitOfWeight,
                             int totalValue,
                             QObject *parent) :
    QObject{parent},
    limitOfWeight{limitOfWeight},
    limitOfValue{totalValue},
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
    optimalObjectsValue = 0;
    int totalValue = 0;
    for (SomeObject *object : objects) {
        totalValue += object->getValue();
    }

    // начинаем собирать набор
    tryJoin(0, 0, totalValue, objects);

    return selectedOptimalObjects;
}

void OptimalChoice::tryJoin(int i, QList<SomeObject *> objects)
{
    // подготовка
    int tempCurrentObjectsWeight;
    int tempCurrentObjectsValue;

    // сам алгоритм
    if (i < objects.size()) {
        // проверка включения обьекта в набор
        tempCurrentObjectsWeight = currentObjectsWeight +
                                   objects.value(i)->getWeight();
        if (tempCurrentObjectsWeight <= limitOfWeight) {
            selectedCurrentObjects.insert(objects.value(i));
            currentObjectsWeight += tempCurrentObjectsWeight;
            tryJoin(i+1, objects);
            selectedCurrentObjects.remove(objects.value(i));
            currentObjectsWeight -= tempCurrentObjectsWeight;
        }
        // проверка исключения обьекта из набора
        tempCurrentObjectsValue = allObjectsValue -
                                  objects.value(i)->getValue();
        if (tempCurrentObjectsValue > limitOfValue) {
            allObjectsValue += tempCurrentObjectsValue;
            tryJoin(i+1, objects);
            allObjectsValue -= tempCurrentObjectsValue;
        }
    }
    // если появился новый оптимальный набор - пишем его
    else if(allObjectsValue > optimalObjectsValue) {
        optimalObjectsValue = allObjectsValue;
        selectedOptimalObjects = selectedCurrentObjects;
    }
}
