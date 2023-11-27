#ifndef MAN_H
#define MAN_H

#include "women.h"

#include <QObject>
#include <QHash>

class Women;

class Man : public QObject
{
    Q_OBJECT
public:
    explicit Man(QObject *parent = nullptr);

private:
    short maxRateValue = 100;
    QHash<Women, short> rateOfWomens; // условный список доступных женщин
    // с уровнем предпочтения в виде числа (меньше число - выше предпочтение)

};

#endif // MAN_H
