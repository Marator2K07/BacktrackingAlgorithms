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
/// случае: существует предел условного веса обьектов и предел
/// суммарной ценности выбранных обьектов
class OptimalChoice : public QObject
{
    Q_OBJECT
public:
    explicit OptimalChoice(QObject *parent = nullptr);
    OptimalChoice(int limitOfWeight,
                  int totalValue,
                  QObject *parent = nullptr);

    int getLimitOfWeight() const;
    void setLimitOfWeight(int newLimitOfWeight);
    int getLimitOfValue() const;
    void setLimitOfValue(int newLimitOfValue);

    ///
    /// \brief selection
    /// простое вычисление оптимального набора обьектов на выходе
    /// для текущих заданных настроек (предельный вес и ценность)
    /// и входящей группы обьектов
    QSet<SomeObject *> selection(QList<SomeObject *> objects);

private:
    int limitOfWeight; // предел веса для обьектов
    int limitOfValue; // предел ценности обьектов
    QSet<SomeObject *> selectedCurrentObjects; // текущее состояние собираемого набора
    QSet<SomeObject *> selectedOptimalObjects; // оптимальный набор среди
    // иследованных на данный момент обьектов
    int currentObjectsWeight; // полный вес набора selectedCurrentObjects
    int allObjectsValue; // общая ценность всех обьектов, переданных в параметре
    int optimalObjectsValue; // общая ценность оптимального набора

    ///
    /// \brief tryJoin
    /// попытка присоединить условный обьект из
    /// списка к текущему набору
    void tryJoin(int i, QList<SomeObject *> objects);
};

#endif // OPTIMALCHOICE_H
