#ifndef EIGHTQUEENSPROBLEM_H
#define EIGHTQUEENSPROBLEM_H

#include <QObject>

///
/// \brief The EightQueensProblem class
/// Задача о восьми ферзях: суть в том, чтобы
/// ни одна из королев не могла побить любую другую.
/// То есть - все они должны быть расставлены по шахматной
/// доске безопасно относительно друг друга
class EightQueensProblem : public QObject
{
    Q_OBJECT
public:
    explicit EightQueensProblem(QObject *parent = nullptr);

private:
    static short const arrSize = 8;
    int x[arrSize]{-1}; // положение ферзей в столбцах
    bool a[arrSize]{true}; // отсутствие ферзей в рядах
    bool b[arrSize*2]; // отсутствие ферзей в / - диагоналях
    bool c[arrSize*2]; // отсутствие ферзей в \ - диагоналях

};

#endif // EIGHTQUEENSPROBLEM_H
