#include "someobject.h"

SomeObject::SomeObject(QObject *parent) :
    QObject{parent},
    weight{0},
    value{0}
{
}

SomeObject::SomeObject(int weight, int value) :
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

int SomeObject::getValue() const
{
    return value;
}

void SomeObject::setValue(int newValue)
{
    value = newValue;
}
