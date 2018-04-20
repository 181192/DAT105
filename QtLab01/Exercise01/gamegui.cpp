#include "gamegui.h"
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

GameGui::GameGui(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(500, 50);
    auto *outerLayout = new QGridLayout(this);
    newGameButton = new QPushButton("New Game");

    for (int i = 0; i < numberOfButtons; ++i) {
        auto *button = buttons[i];
        button = new QPushButton(QString::number(i));

        button->heightForWidth(true);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button->setDisabled(true);

        connect(button , &QPushButton::clicked, this, [i] () { qInfo() << i << " button pressed!"; });

        outerLayout->addWidget(button, 0 , i);

        if (i == numberOfButtons - 1) {
            newGameButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(newGameButton, &QPushButton::clicked, this, [this] () { emit newGameClicked(); });
            outerLayout->addWidget(newGameButton, 0 , i + 1, 0, 2);
        }
    }
}

GameGui::~GameGui() {

}

void GameGui::setupButtons()
{
    for (auto b : buttons) {
        b->setVisible(true);
    }
}

void GameGui::changeColor(int i)
{
    i++;

}
