#include <QCoreApplication>

#include "chessboard.h"
#include "journeyofchessknight.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Chessboard *chessboard = new Chessboard(5);
    chessboard->clear();
    JourneyOfChessKnight *knightJournay = new JourneyOfChessKnight();

    qInfo() << "Start application";
    chessboard->print();
    knightJournay->startTour(chessboard, 2, 2);
    qInfo() << "After journay";
    chessboard->print();

    return a.exec();
}
