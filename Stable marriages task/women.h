#ifndef WOMEN_H
#define WOMEN_H

#include "man.h"

#include <QObject>
#include <QHash>

class Man;

class Women : public QObject
{
    Q_OBJECT
public:
    explicit Women(QObject *parent = nullptr);

private:
    short maxRateValue = 100;
    QHash<Man, short> rateOfMans; // условный список доступных мужчин
    // с уровнем предпочтения в виде числа (меньше число - выше предпочтение)

};

#endif // WOMEN_H
