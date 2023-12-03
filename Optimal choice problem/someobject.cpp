#include "someobject.h"

SomeObject::SomeObject(QObject *parent) :
    QObject{parent},
    weight{5},
    value{10}
{
}

SomeObject::SomeObject(int weight,
                       int value,
                       QObject *parent) :
    QObject{parent},
    weight(weight),
    value(value)
{
}

int SomeObject::getWeight() const
{
    return weight;
}

void SomeObject::setWeight(int newWeight)
{
    weight = newWeight;
}

void SomeObject::setRandomWeight()
{
    weight = QRandomGenerator::global()->bounded(0, maxWeight);
}

int SomeObject::getValue() const
{
    return value;
}

void SomeObject::setValue(int newValue)
{
    value = newValue;
}

void SomeObject::setRandomValue()
{
    value = QRandomGenerator::global()->bounded(0, maxValue);
}
