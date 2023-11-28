#include "women.h"

Women::Women(QObject *parent)
    : QObject{parent}
{

}

void Women::randomlyFillRates(QList<Man *> mens)
{
    QSet<short> usedRates;
    // записываем рейтинг
    foreach (Man *men, mens) {
        short thisRate;
        // делаем так, чтобы рейтинг не повторялся
        do {
            thisRate = QRandomGenerator::global()->bounded(0, maxRateValue);
        } while (usedRates.contains(thisRate));
        // если рейтинг уникален, можно идти дальше
        usedRates.insert(thisRate);
        rateOfMans.insert(men, thisRate);
    }
}

short Women::getRate(Man *man)
{
    return rateOfMans[man];
}

void Women::printRates()
{
    QTextStream out(stdout);
    short i = 1;
    out << "Women " << this << " appreciates:\n";
    for (auto [key, value] : rateOfMans.asKeyValueRange()) {
        out << i++ <<")Men: " << key << "; his rate - " << value << ";\n";
    }
}
