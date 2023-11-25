#include <QCoreApplication>

#include "journeyofchessknight.h"
#include "eightqueensproblem.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Chessboard *chessboard = new Chessboard(8);
    chessboard->clear();    

    qInfo() << "Start application";
    chessboard->print();

    //JourneyOfChessKnight *knightJournay = new JourneyOfChessKnight();
    //knightJournay->startTour(chessboard, 2, 2);
    //qInfo() << "After journay";
    //chessboard->print();

    EightQueensProblem *queensProblem = new EightQueensProblem();
    queensProblem->setChessboard(chessboard);
    bool done = queensProblem->attemptToSolve();
    if (done) {
        qInfo() << "Result:";
        chessboard->print();
    } else {
        qInfo() << "Error";
    }

    return a.exec();
}
