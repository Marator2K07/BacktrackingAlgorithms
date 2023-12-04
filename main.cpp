#include <QCoreApplication>

#include "journeyofchessknight.h"
#include "eightqueensproblem.h"

#include "Stable marriages task/stablemarriages.h"
#include "Optimal choice problem/optimalchoice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Chessboard *chessboard = new Chessboard(8);
    //chessboard->clear();

    //qInfo() << "Start application";
    //chessboard->print();

    //JourneyOfChessKnight *knightJournay = new JourneyOfChessKnight();
    //knightJournay->startTour(chessboard, 2, 2);
    //qInfo() << "After journay";
    //chessboard->print();

    /*
    EightQueensProblem *queensProblem = new EightQueensProblem();
    queensProblem->setChessboard(chessboard);
    // если нужно найти первое доступное решение задачи
    bool done = queensProblem->attemptToSolve();
    if (done) {
        qInfo() << "Result:";
        chessboard->print();
    } else {
        qInfo() << "Error";
    }
    // чтобы найти все доступные решения
    short solutionsCount = queensProblem->allSolutions();
    qInfo() << "Solutions founded: " << solutionsCount;
    */

    /*
    StableMarriages stableMarriages(5);
    stableMarriages.printInfo();
    stableMarriages.findThem();
    */

    // Создаем и инициализируем список условных обьектов
    QList<SomeObject *> objects;
    short countOfObjects = 22;
    for (int i = 0; i < countOfObjects; ++i) {
        SomeObject *newObject = new SomeObject;
        newObject->setRandomWeight();
        newObject->setRandomValue();
        newObject->printInfo();
        objects.append(newObject);
    }

    return a.exec();
}
