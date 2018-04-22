#include "gamegui.h"
#include "gameengine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameEngine engine;
    GameGui game(&engine);
    game.show();

    return a.exec();
}
