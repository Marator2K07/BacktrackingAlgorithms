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

void OptimalChoice::tryJoin(int i,
                            int currentObjW,
                            int potentialObjV,
                            QList<SomeObject *> objects)
{
    // подготовка
    int tempCurrentObjectsWeight;
    int tempPotentialObjectsValue;

    // сам алгоритм
    if (i < objects.size()) {
        // проверка включения обьекта в набор
        tempCurrentObjectsWeight = currentObjW +
                                   objects.value(i)->getWeight();
        if (tempCurrentObjectsWeight <= limitOfWeight) {
            selectedCurrentObjects.insert(objects.value(i));
            tryJoin(i+1, tempCurrentObjectsWeight, potentialObjV, objects);
            selectedCurrentObjects.remove(objects.value(i));
        }
        // проверка исключения обьекта из набора
        tempPotentialObjectsValue = potentialObjV -
                                    objects.value(i)->getValue();
        if (tempPotentialObjectsValue > limitOfValue) {
            tryJoin(i+1, currentObjW, potentialObjV, objects);
        }
    }
    // если появился новый оптимальный набор - пишем его
    else if(potentialObjV > optimalObjectsValue) {
        optimalObjectsValue = potentialObjV;
        selectedOptimalObjects = selectedCurrentObjects;
    }
}
