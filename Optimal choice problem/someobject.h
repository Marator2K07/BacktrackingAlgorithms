#ifndef SOMEOBJECT_H
#define SOMEOBJECT_H

#include <QObject>

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

private:
    int weight; // условный вес данного обьекта
    int value; // ценность этого обьекта

};

#endif // SOMEOBJECT_H
