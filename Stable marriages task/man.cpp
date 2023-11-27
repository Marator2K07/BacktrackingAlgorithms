#include "man.h"

Man::Man(QObject *parent)
    : QObject{parent}
{

}

void Man::randomlyFillRates(QList<Women *> womens)
{
    QSet<short> usedRates;
    // записываем рейтинг
    foreach (Women *women, womens) {
        short thisRate;
        // делаем так, чтобы рейтинг не повторялся
        do {
            thisRate = QRandomGenerator::global()->bounded(0, maxRateValue);
        } while (usedRates.contains(thisRate));
        // если рейтинг уникален, можно идти дальше
        usedRates.insert(thisRate);
        rateOfWomens.insert(women, thisRate);
    }
}
