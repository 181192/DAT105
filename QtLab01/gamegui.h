#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QWidget>
#include <QPushButton>
#include "igameengine.h"

class GameGui : public QWidget
{
    Q_OBJECT

public:
    explicit GameGui(IGameEngine *engine, QWidget *parent = 0);
    ~GameGui();

private:
    int NUMBER_OF_BUTTONS;
    QPushButton **buttonRow;
    QPushButton *newGameButton;
    IGameEngine *engine;

public slots:
    void buttonPressed();
    void resetGame();


};

#endif // GAMEGUI_H
