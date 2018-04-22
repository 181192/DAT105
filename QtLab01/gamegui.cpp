#include "gamegui.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

GameGui::GameGui(IGameEngine *m, QWidget *parent)
    : QWidget(parent)
{
    engine = m;
    NUMBER_OF_BUTTONS = 10;
    buttons = new QPushButton* [NUMBER_OF_BUTTONS];
    this->setMinimumSize(500, 50);
    auto *outerLayout = new QGridLayout(this);

    newGameButton = new QPushButton("Nytt spill");
    newGameButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(newGameButton, &QPushButton::released, this, &GameGui::resetGame);

    for (int i = 0; i < NUMBER_OF_BUTTONS; ++i) {
        auto *button = buttons[i];
        button = new QPushButton(QString::number(i));

        button->heightForWidth(true);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button->setDisabled(true);

        outerLayout->addWidget(button, 0 , i, 0, 1);
        connect(button , &QPushButton::released, this, &GameGui::buttonPressed);

        if (i == NUMBER_OF_BUTTONS - 1)
            outerLayout->addWidget(newGameButton, 0 , i + 1, 0, 2);
    }
}

GameGui::~GameGui() {

}

void GameGui::buttonPressed()
{
    auto *button = (QPushButton*) sender();
    auto guess = button->text().toInt();
    auto res = engine->guessNumber(guess);

    if (res == 0) {
        button->setStyleSheet("* { background-color: green }");
        newGameMessage();
    }
    else if (res < 0)
        for (int i = 0; i <= guess; ++i) {
            buttons[i]->setStyleSheet("* { background-color: red }");
            buttons[i]->setDisabled(true);
        }
    else if ( res > 0)
        for (int i = 0; guess < NUMBER_OF_BUTTONS; ++i) {
            buttons[i]->setStyleSheet("* { background-color: red }");
            buttons[i]->setDisabled(true);
        }

    qInfo() << button->text() << " pressed!";

}

void GameGui::newGameMessage() {
    QString msg = "Du klarte det på "
            + QString::number(engine->findNumberOfGuess())
            + " forsøk!\n";
    int res = QMessageBox::question(this, "Spille igjen?", msg + "Spille igjen?", QMessageBox::Yes, QMessageBox::No);

    if (res == QMessageBox::Yes)
        newGameButton->setEnabled(true);
    else if ( res == QMessageBox::No )
        exit(0);
}

void GameGui::resetGame()
{
    engine->init();

    for (int i = 0; i < NUMBER_OF_BUTTONS; ++i) {
        qInfo() << buttons[i]->text();
        buttons[i]->setStyleSheet("* { background-color: lightgrey }");
        buttons[i]->setEnabled(true);
    }

    newGameButton->setDisabled(true);
}
