#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hangmanwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(IHangmanLogic *hl, QWidget *parent = 0);
    ~MainWindow();
private:
    HangmanWidget *widget;
};

#endif // MAINWINDOW_H
