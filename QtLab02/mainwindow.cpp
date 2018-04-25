#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(IHangmanLogic *hl, QWidget *parent) : QMainWindow(parent)
{
    widget = new HangmanWidget(hl, this);

    QMenu* file_menu = new QMenu("File", this);
    QMenu* option_menu = new QMenu("Options", this);
    QAction* quit_action = file_menu->addAction("Quit");
    QMenuBar* menu_bar = new QMenuBar();
    setMenuBar(menu_bar);
    menu_bar->addMenu(file_menu);
    menu_bar->addMenu(option_menu);

    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}
