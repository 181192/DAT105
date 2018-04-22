#ifndef GAME_H
#define GAME_H

#include "igameengine.h"

class GameEngine : public IGameEngine
{

public:
    GameEngine();
    void init() override;
    int guessNumber(int i) override;
    int findNumberOfGuess() override;

private:
    int secretNumber;
    int numberOfGuess;
};

#endif // GAME_H
