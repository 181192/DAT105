#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT

public slots:
    void buttonPressed(int i);
    void startNewGame();
    void gameFinished();


signals:
    void buttonClicked(int);
    void gameFinnished(bool);

};

#endif // GAME_H
