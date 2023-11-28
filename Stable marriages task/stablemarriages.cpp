#include "stablemarriages.h"

StableMarriages::StableMarriages(short numberOfPairs, QObject *parent)
    : numberOfPairs{numberOfPairs}, QObject{parent}
{
    // сначала заполним списки обьектами
    for (int i = 0; i < numberOfPairs; ++i) {
        mans.append(new Man);
        womens.append(new Women);
    }
    // заполняем рейтинги женщин для каждого мужика
    for (Man *man : mans) {
        man->randomlyFillRates(womens);
    }
    // а теперь заполняем рейтинг мужчин для женщин
    for (Women *women : womens) {
        women->randomlyFillRates(mans);
    }
    // изначально все женщины свободны
    for (Women *women : womens) {
        single.insert(women, true);
    }
}

bool StableMarriages::isStable()
{
    bool stable = true; // будущий результат метода
    short index = -1;

    // ..
}

void StableMarriages::printInfo()
{
    // вывод рейтингов для мужчин
    for (Man *man : mans) {
        man->printRates();
    }
    // вывод рейтингов для женщин
    for (Women *women : womens) {
        women->printRates();
    }
}
