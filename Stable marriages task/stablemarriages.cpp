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

bool StableMarriages::isStable(Man *man, Women *women)
{
    bool stable = true; // будущий результат

    // проверка, есть ли лучший вариант со стороны мужчины
    short currentWomenRate = man->getRate(women);
    for (Women *women : womens) {
        // если какая то женщина подходит лучше и она уже замужем
        if (man->getRate(women) < currentWomenRate) {
            if (!single[women]) {
                stable = false;
                break;
            }
        }
    }
    // проверка, есть ли лучший вариант со стороны женщины
    short currentManRate = women->getRate(man);
    for (Man *man : mans) {
        // если какой-то мужчина подходит лучше
        if (women->getRate(man) < currentManRate) {
            stable = false;
            break;
        }
    }

    return stable;
}

void StableMarriages::tryFindCouple(short manIndex)
{
    // подготовка
    Man *thisMan = mans.value(manIndex);

    // пытаемся найти пару
    if (manIndex < numberOfPairs) {
        // смотрим всех претенденток
        for (Women *women : womens) {
            // если женщина свободна и брак будет предположительно стабильным
            if (single[women] && isStable(thisMan, women)) {
                // официально обьявляем парочку
                couples.insert(thisMan, women);
                single[women] = false;
                // пытаемся найти следующую
                tryFindCouple(manIndex + 1);
                // отменяем ход для будущих решений
                single[women] = true;
            }
        }
    } else {
        // пишем статистику по найденному решению
        printStatisticsOfSolution();
    }
}

void StableMarriages::printStatisticsOfSolution()
{
    QTextStream out(stdout);
    short i = 0;
    // вывод полученных текущих парочек
    out << "Couples:\n";
    for (auto [man, women] : couples.asKeyValueRange()) {
        out << i++ <<")Man: " << man <<
            QString("[with rate - %1]").
            arg(dynamic_cast<Women *>(women)->getRate(man)) <<
            ";\n his wife: " << women <<
            QString("[with rate - %1]").
            arg(dynamic_cast<Man *>(man)->getRate(women)) <<
            ";\n";
    }
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
