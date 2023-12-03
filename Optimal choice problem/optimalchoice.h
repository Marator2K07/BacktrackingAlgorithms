#ifndef OPTIMALCHOICE_H
#define OPTIMALCHOICE_H

#include <QObject>

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

private:
    int limitOfWeight; // предел веса для n обьектов
    int limitOfValue; // суммарная ценность n обьектов
};

#endif // OPTIMALCHOICE_H
