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

StableMarriages::~StableMarriages()
{
    for (Man *man : mans) {
        delete man;
    }
    for (Women *women : womens) {
        delete women;
    }
}

bool StableMarriages::isStable(Man *man,
                               Women *women,
                               short pos)
{
    short index = pos;

    // проверка, есть ли лучший вариант со стороны мужчины
    short currentWomenRate = man->getRate(women);
    while (index < numberOfPairs) {
        // если какая-то женщина подходит лучше, то с данной
        // отношений не будет, иначе это был бы не стабильный брак
        if (man->getRate(womens[index]) < currentWomenRate) {
            // но при этом, лучше подходящая - должна быть свободна
            if (single[womens[index]]) {
                return false;
            }
        }
        index++;
    }

    // проверка, есть ли лучший вариант со стороны женщины
    index = pos;
    short currentManRate = women->getRate(man);
    while (index < numberOfPairs) {
        // если какой-то мужчина подходит лучше
        if (women->getRate(man) < currentManRate) {
            return false;
        }
        index++;
    }

    return true;
}

void StableMarriages::tryFindCouple(short manIndex)
{
    // подготовка
    Man *thisMan = mans.value(manIndex);

    // пытаемся найти пару
    if (manIndex < numberOfPairs) {
        // смотрим всех претенденток
        for (int i = 0; i < numberOfPairs; ++i) {
            Women *thisWomen = womens.value(i);
            // если женщина свободна и брак будет предположительно стабильным
            if (single[thisWomen] && isStable(thisMan, thisWomen, i)) {
                // официально обьявляем парочку
                couples.insert(thisMan, thisWomen);
                single[thisWomen] = false;
                // пытаемся найти следующую
                tryFindCouple(manIndex + 1);
                // отменяем ход для будущих решений
                couples.remove(thisMan);
                single[thisWomen] = true;
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

void StableMarriages::findThem()
{
    // для последующих корректных вызовов
    if (couples.count() > 0) {
        couples.clear();
    }
    // начинаем алгоритм с первой(нулевой) пары
    tryFindCouple(0);
}
