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
}
