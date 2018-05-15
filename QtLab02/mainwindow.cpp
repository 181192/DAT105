#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QInputDialog>

MainWindow::MainWindow(HangmanLogic *hl, QWidget *parent) : QMainWindow(parent)
{
    resize(this->sizeHint());

    engine = hl;
    widget = new HangmanWidget(hl, this);
    setCentralWidget(widget);

    auto *fileMenu = new QMenu("&File", this);
    auto *optionMenu = new QMenu("&Options", this);
    auto *menu_bar = new QMenuBar();

    new QAction(optionMenu->addAction("&New Game", this, &MainWindow::startNewGame, Qt::CTRL | Qt::Key_N));
    new QAction(optionMenu->addAction("&Restart Game", widget, &HangmanWidget::reset, Qt::CTRL | Qt::Key_R));
    new QAction(fileMenu->addAction("&Exit", this, &MainWindow::close, Qt::CTRL | Qt::Key_Q));

//    auto *newGameAction = new QAction(optionMenu->addAction("&New Game", hl, &HangmanLogic::startNewGame, Qt::CTRL | Qt::Key_N));
//    auto *restartAction = new QAction(optionMenu->addAction("&Restart Game", hl, &HangmanLogic::restartGame, Qt::CTRL | Qt::Key_R));
//    auto *closeAction = new QAction(fileMenu->addAction("&Exit", this, &MainWindow::close, Qt::CTRL | Qt::Key_Q));

    setMenuBar(menu_bar);
    menu_bar->addMenu(fileMenu);
    menu_bar->addMenu(optionMenu);

    connect(widget, &HangmanWidget::guessMade, hl, &HangmanLogic::guess);

    connect(hl, &HangmanLogic::resetUi,             widget, &HangmanWidget::reset);
    connect(hl, &HangmanLogic::setButtonGreen,      widget, &HangmanWidget::setButtonGreen);
    connect(hl, &HangmanLogic::setButtonRed,        widget, &HangmanWidget::setButtonRed);
    connect(hl, &HangmanLogic::updateAttemptsLeft,  widget, &HangmanWidget::setAttemptsLeft);
    connect(hl, &HangmanLogic::updateHiddenMessage, widget, &HangmanWidget::setHiddenMessage);
    connect(hl, &HangmanLogic::updateStatusMessage, widget, &HangmanWidget::setStatusMessage);
    connect(hl, &HangmanLogic::gameOver,            widget, &HangmanWidget::gameOver);
}

void MainWindow::startNewGame(void)
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter hidden word/sentence"),
                                         tr("Word/sentence: "), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
        engine->startNewGame(text);
}

MainWindow::~MainWindow()
{
}
