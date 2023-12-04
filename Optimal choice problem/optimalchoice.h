#ifndef OPTIMALCHOICE_H
#define OPTIMALCHOICE_H

#include <QObject>
#include <QSet>
#include <QList>

#include "someobject.h"

///
/// \brief The OptimalChoice class
/// основной класс для нахождения оптимального решения
/// поставленной задачи с ограничительными условиями, в нашем
/// случае: существует предел условного веса обьектов
class OptimalChoice : public QObject
{
    Q_OBJECT
public:
    explicit OptimalChoice(QObject *parent = nullptr);
    OptimalChoice(int limitOfWeight,
                  QObject *parent = nullptr);

    int getLimitOfWeight() const;
    void setLimitOfWeight(int newLimitOfWeight);

    ///
    /// \brief selection
    /// простое вычисление оптимального набора обьектов на выходе
    /// для текущих заданных настроек (предельный вес и ценность)
    /// и входящей группы обьектов
    QSet<SomeObject *> selection(QList<SomeObject *> objects);

private:
    int limitOfWeight; // предел веса для обьектов
    int optimalObjectsValue; // общая ценность оптимального набора
    QSet<SomeObject *> selectedCurrentObjects; // текущее состояние собираемого набора
    QSet<SomeObject *> selectedOptimalObjects; // оптимальный набор среди
    // иследованных на данный момент обьектов

    ///
    /// \brief tryJoin
    /// попытка присоединить условный обьект из
    /// списка к текущему набору
    void tryJoin(int i,
                 int currentObjW,
                 int potentialObjV,
                 QList<SomeObject *> objects);
};

#endif // OPTIMALCHOICE_H
