#include "gamegui.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

GameGui::GameGui(IGameEngine *m, QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(500, 50);
    auto *outerLayout = new QGridLayout(this);

    engine = m;
    NUMBER_OF_BUTTONS = 20;
    buttons = new std::vector<QPushButton*>();

    newGameButton = new QPushButton("Nytt spill");
    newGameButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(newGameButton, &QPushButton::released, this, &GameGui::resetGame);

    for (int i = 0; i < NUMBER_OF_BUTTONS; ++i) {
        auto button = new QPushButton(QString::number(i));
        buttons->push_back(button);

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

    if (res < 0)
        for (int i = 0; i <= guess; ++i) {
            auto *b = buttons->at(i);
            b->setStyleSheet("* { background-color: red }");
            b->setDisabled(true);
        }
    else if ( res > 0)
        for (int i = 0; guess < NUMBER_OF_BUTTONS; ++i) {
            auto *b = buttons->at(i);
            b->setStyleSheet("* { background-color: red }");
            b->setDisabled(true);
        }
    else {
        button->setStyleSheet("* { background-color: green }");
        newGameMessage();
    }
}

void GameGui::newGameMessage() {
    QString msg = "Du klarte det på "
            + QString::number(engine->findNumberOfGuess())
            + " forsøk!\n";
    int qst = QMessageBox::question(this, "Spille igjen?", msg + "Spille igjen?", QMessageBox::Yes, QMessageBox::No);

    if (qst == QMessageBox::Yes)
        newGameButton->setEnabled(true);
    else if ( qst == QMessageBox::No )
        exit(0);
}

void GameGui::resetGame()
{
    engine->init();

    for (int i = 0; i < NUMBER_OF_BUTTONS; ++i) {
        auto *button = buttons->at(i);
        button->setStyleSheet("* { background-color: lightgrey }");
        button->setEnabled(true);
    }

    newGameButton->setDisabled(true);
}
