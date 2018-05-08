#include "hangmanwidget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include <QDebug>

HangmanWidget::HangmanWidget(HangmanLogic *hl, QWidget *parent) : QWidget(parent)
{
    engine = hl;
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    alphabetButtons = new std::vector<QPushButton*>();

    outerLayout = new QHBoxLayout(this);
    rightColumn = new QVBoxLayout();
    leftColumn = new QVBoxLayout();
    alphabetGrid = new QGridLayout();

    wordLabel = new QLabel();
    attempsLabel = new QLabel();
    statusLabel = new QLabel();
    hangmanLabel = new QLabel();

    outerLayout->addLayout(leftColumn);
    outerLayout->addLayout(rightColumn);

    leftColumn->addWidget(wordLabel);
    leftColumn->addWidget(attempsLabel);
    leftColumn->addWidget(statusLabel);

    int row, column, i = 0;
    for (QChar c : alphabet) {
        if (i++ % 4 == 0) {
            ++row;
            column = 0;
        }

        auto *button = new QPushButton(c);
        alphabetButtons->push_back(button);
        alphabetGrid->addWidget(button, row, ++column);
        connect(button, &QPushButton::clicked, this, &HangmanWidget::buttonPressed);
    }

    leftColumn->addLayout(alphabetGrid);

    hangmanLabel->setPixmap(getHangmanImage(0));
    rightColumn->addWidget(hangmanLabel);
}

void HangmanWidget::reset()
{
    emit engine->restartGame();
}

void HangmanWidget::setHiddenMessage(QString msg)
{
    wordLabel->setText(msg);
}

void HangmanWidget::setStatusMessage(QString msg)
{
    statusLabel->setText(msg);
}

void HangmanWidget::buttonPressed() {
    auto *button = (QPushButton*) sender();
    QChar c = button->text().at(0);
    qInfo() << c.toLatin1() << " pressed!";
    emit guessMade(c);

}

void HangmanWidget::setButtonGreen()
{
    auto *button = (QPushButton*) sender();
    button->setStyleSheet("* { background-color: green }");
}

void HangmanWidget::setButtonRed()
{
    auto *button = (QPushButton*) sender();
    button->setStyleSheet("* { background-color: red }");
}

void HangmanWidget::setAttemptsLeft(unsigned int attemptsLeft)
{
    hangmanLabel->setPixmap(getHangmanImage(attemptsLeft));
}

void HangmanWidget::gameOver()
{
    gameOverBool = true;
}


QPixmap HangmanWidget::getHangmanImage(unsigned int num)
{
    QPixmap image;

    switch(num) {
    case 0:
        image.load("../images/hangman0.png");
        break;
    case 1:
        image.load("../images/hangman1.png");
        break;
    case 2:
        image.load("../images/hangman2.png");
        break;
    case 3:
        image.load("../images/hangman3.png");
        break;
    case 4:
        image.load("../images/hangman4.png");
        break;
    case 5:
        image.load("../images/hangman5.png");
        break;
    case 6:
        image.load("../images/hangman6.png");
        break;
    case 7:
        image.load("../images/hangman7.png");
        break;
    default:
        image.load("../images/hangman0.png");
        break;
    }

    return image;
}

