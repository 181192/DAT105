#ifndef HANGMANWIDGET_H
#define HANGMANWIDGET_H

#include "ihangmanlogic.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>

class HangmanWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HangmanWidget(IHangmanLogic *hl, QWidget *parent = nullptr);

private:
    IHangmanLogic *engine;

    QHBoxLayout *outerLayout;
    QVBoxLayout *rightColumn;
    QVBoxLayout *leftColumn;

    QLabel *wordLabel;
    QLabel *attempsLabel;
    QLabel *statusLabel;
    QLabel *hangmanLabel;

    std::vector<QPushButton*> *alphabetButtons;
    QGridLayout *alphabetGrid;

    QPixmap image;
    QString alphabet;

signals:
    void guessMade(char c);

public slots:
    void reset();
    void setHiddenMessage(QString msg);
    void buttonPressed(char c);
    void setButtonGreen(char c);
    void setButtonRed(char c);
    void setAttemptsLeft(unsigned int attemptsLeft);
};

#endif // HANGMANWIDGET_H
