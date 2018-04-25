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

    QHBoxLayout *outerLayout = new QHBoxLayout(this);
    QVBoxLayout *rightColumn = new QVBoxLayout();
    QVBoxLayout *leftColumn = new QVBoxLayout();

    outerLayout->addLayout(leftColumn);
    outerLayout->addLayout(rightColumn);

    QLabel *wordLabel = new QLabel("Example");
    QLabel *attempsLabel = new QLabel("Attempts left: 3");
    QLabel *statusLabel = new QLabel("Status Label");
    QLabel *hangmanLabel = new QLabel();

    QPushButton *p = new QPushButton("Eyy");

    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    auto alphabetButtons = new std::vector<QPushButton*>();


    leftColumn->addWidget(wordLabel);
    leftColumn->addWidget(attempsLabel);
    leftColumn->addWidget(statusLabel);

    QGridLayout *alphabetGrid = new QGridLayout();

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

    QPixmap image;
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
