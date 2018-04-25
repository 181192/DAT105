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
    QPushButton *p = new QPushButton("Eyy");

    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    auto alphabetButtons = new std::vector<QPushButton*>();


    leftColumn->addWidget(wordLabel);
    leftColumn->addWidget(attempsLabel);
    leftColumn->addWidget(statusLabel);

    QGridLayout *alphabetGrid = new QGridLayout();
    int row = 0;
    int column = 0;
    int i = 0;
    for (QChar c : alphabet) {
        auto *button = new QPushButton(c);
        alphabetButtons->push_back(button);

        if (i % 4 == 0) {
            row++;
            column = 0;
        }
        alphabetGrid->addWidget(button, row, ++column);
        i++;
    }


    leftColumn->addLayout(alphabetGrid);
    rightColumn->addWidget(p);




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
