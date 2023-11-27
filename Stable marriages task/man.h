#ifndef MAN_H
#define MAN_H

#include "women.h"

#include <QObject>
#include <QHash>
#include <QRandomGenerator>
#include <QSet>
#include <QTextStream>

class Women;

class Man : public QObject
{
    Q_OBJECT
public:
    explicit Man(QObject *parent = nullptr);

private:
    short maxRateValue = 100;
    QHash<Women *, short> rateOfWomens; // условный список доступных женщин
    // с уровнем предпочтения в виде числа (меньше число - выше предпочтение)

public:
    ///
    /// \brief randomlyFillRates
    /// случаное заполнение рейтингов женщин для данного обьекта мужчины,
    /// причем рейтинги оценки для каждого отдельного обьекта - всегда разные
    void randomlyFillRates(QList<Women *> womens);
    void printRates();

};

#endif // MAN_H
