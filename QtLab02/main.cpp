#include "mainwindow.h"
#include "hangmanlogic.h"
#include "hangmanwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HangmanLogic hl;
    MainWindow w(&hl);
    w.show();

    return a.exec();
}
