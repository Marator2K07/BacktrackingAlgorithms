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
    int getTotalValue() const;
    void setTotalValue(int newTotalValue);

private:
    int limitOfWeight; // предел веса для n обьектов
    int totalValue; // суммарная ценность n обьектов
};

#endif // OPTIMALCHOICE_H
