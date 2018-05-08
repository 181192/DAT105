#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hangmanwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    HangmanLogic *engine;

public:
    MainWindow(HangmanLogic *hl, QWidget *parent = 0);
    ~MainWindow();
private:
    HangmanWidget *widget;
private slots:
    void startNewGame();
};

#endif // MAINWINDOW_H
