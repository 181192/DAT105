#include "hangmanwidget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include <algorithm>

HangmanWidget::HangmanWidget(IHangmanLogic *hl, QWidget *parent) : QWidget(parent)
{
    engine = hl;
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    alphabetButtons = new std::vector<QPushButton*>();

    outerLayout = new QHBoxLayout(this);
    rightColumn = new QVBoxLayout();
    leftColumn = new QVBoxLayout();
    alphabetGrid = new QGridLayout();

    wordLabel = new QLabel("Example");
    attempsLabel = new QLabel("Attempts left: 3");
    statusLabel = new QLabel("Status Label");
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

        alphabetButtons->push_back(new QPushButton(c));
        alphabetGrid->addWidget(alphabetButtons->back(), row, ++column);
    }

    leftColumn->addLayout(alphabetGrid);

    image.load("../images/hangman0.png");
    hangmanLabel->setPixmap(image);
    rightColumn->addWidget(hangmanLabel);

}

void HangmanWidget::reset()
{

}

void HangmanWidget::setHiddenMessage(QString msg)
{

}

void HangmanWidget::buttonPressed(char c)
{

}

void HangmanWidget::setButtonGreen(char c)
{

}

void HangmanWidget::setButtonRed(char c)
{

}

void HangmanWidget::setAttemptsLeft(unsigned int attemptsLeft)
{

}
