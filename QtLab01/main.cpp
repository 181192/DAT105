#include "gamegui.h"
#include "gameengine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameGui myGameGui;
    GameEngine myGame;

    myGameGui.show();

    QObject::connect(&myGameGui, SIGNAL(newGameClicked()), &myGame, SLOT(startNewGame()));
    QObject::connect(&myGameGui, SIGNAL(newGameClicked()), &myGameGui, SLOT(setupButtons()));

    return a.exec();
}
