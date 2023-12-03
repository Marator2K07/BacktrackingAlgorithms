#include "optimalchoice.h"

OptimalChoice::OptimalChoice(QObject *parent) :
    QObject{parent},
    limitOfWeight{500},
    limitOfValue{1000}
{
}

OptimalChoice::OptimalChoice(int limitOfWeight,
                             int totalValue,
                             QObject *parent) :
    QObject{parent},
    limitOfWeight{limitOfWeight},
    limitOfValue{totalValue}
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
