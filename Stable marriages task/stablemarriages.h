#ifndef STABLEMARRIAGES_H
#define STABLEMARRIAGES_H

#include "man.h"
#include "women.h"

#include <QObject>

class StableMarriages : public QObject
{
    Q_OBJECT
public:
    explicit StableMarriages(QObject *parent = nullptr);

private:
    short numberOfPairs; // количество пар браков
    QList<Man *> mans; // список мужчин, доступных для брака
    QList<Women *> women; // список женщин, доступных для брака

};

#endif // STABLEMARRIAGES_H
