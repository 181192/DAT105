#ifndef GAME_H
#define GAME_H

#include "igameengine.h"

class GameEngine : public IGameEngine
{

public:
    GameEngine();
    void init() override;
    void guessNumber(int i) override;
    void findNumberOfGuess() override;

private:
    int secretNumber;
    int numberOfGuess;
};

#endif // GAME_H
