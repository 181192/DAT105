#include "gameengine.h"
#include <QDebug>



GameEngine::GameEngine()
{
    srand(time(0));
}

void GameEngine::init()
{
    secretNumber = rand() % 10;
    numberOfGuess = 0;

}

int GameEngine::guessNumber(int i)
{
    numberOfGuess++;
    if (i < secretNumber )
        return -1;
    else if ( i < secretNumber )
        return 1;
    else
        return 0;
}

int GameEngine::findNumberOfGuess()
{
    return numberOfGuess;
}
