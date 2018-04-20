#ifndef IGAMEENGINE_H
#define IGAMEENGINE_H


class IGameEngine
{
public:
    virtual int guessNumber( int i ) = 0;

    virtual int findNumberOfGuess() = 0;

    virtual void init() = 0;
};

#endif // IGAMEENGINE_H
