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
    QHash<Man *, short> rateOfMans; // условный список доступных мужчин
    // с уровнем предпочтения в виде числа (меньше число - выше предпочтение)

public:
    ///
    /// \brief randomlyFillRates
    /// случаное заполнение рейтингов мужчин для данного обьекта женщины,
    /// причем рейтинги оценки для каждого отдельного обьекта - всегда разные
    void randomlyFillRates(QList<Man *> mens);
    ///
    /// \brief getRate
    /// получить рейтинг выбранной женщины
    short getRate(Man *man);
    void printRates();

};

#endif // WOMEN_H
