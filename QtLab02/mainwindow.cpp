#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(IHangmanLogic *hl, QWidget *parent) : QMainWindow(parent)
{
    widget = new HangmanWidget(hl, this);

    auto *fileMenu = new QMenu("&File", this);
    auto *optionMenu = new QMenu("&Options", this);
    auto *closeAction = new QAction(fileMenu->addAction("&Exit", this, &MainWindow::close, Qt::CTRL+Qt::Key_Q));
    auto *menu_bar = new QMenuBar();

    setMenuBar(menu_bar);
    menu_bar->addMenu(fileMenu);
    menu_bar->addMenu(optionMenu);

    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}
