#include "journeyofchessknight.h"

JourneyOfChessKnight::JourneyOfChessKnight(QObject *parent)
    : QObject{parent}
{
    // инициализация массивов ходов шахматного коня
    movesX = new short[movesSize] {2, 1, -1, -2, -2, -1, 1, 2};
    movesY = new short[movesSize] {1, 2, 2, 1, -1, -2, -2, -1};
}
