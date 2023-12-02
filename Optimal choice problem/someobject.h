#ifndef SOMEOBJECT_H
#define SOMEOBJECT_H

#include <QObject>
#include <QRandomGenerator>

///
/// \brief The SomeObject class
/// класс условного объекта с двумя главными
/// характеристиками: вес и ценность
class SomeObject : public QObject
{
    Q_OBJECT
public:
    explicit SomeObject(QObject *parent = nullptr);
    SomeObject(int weight, int value);

    int getWeight() const;
    void setWeight(int newWeight);
    int getValue() const;
    void setValue(int newValue);

    void setRandomWeight();
    void setRandomValue();

private:
    int weight; // условный вес данного обьекта
    int value; // ценность этого обьекта
    int maxWeight = 100;
    int maxValue = 100;

};

#endif // SOMEOBJECT_H
