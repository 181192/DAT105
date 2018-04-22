#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include <QPushButton>
#include "igameengine.h"

class GameGui : public QWidget
{
    Q_OBJECT

public:
    GameGui(IGameEngine *m, QWidget *parent = 0);
    ~GameGui();

private:
    int NUMBER_OF_BUTTONS;
    QPushButton **buttons;
    QPushButton *newGameButton;
    IGameEngine *engine;

    void newGameMessage();
public slots:
    void buttonPressed();
    void resetGame();


};

#endif // GAMEGUI_H
