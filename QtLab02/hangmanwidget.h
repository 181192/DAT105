#ifndef HANGMANWIDGET_H
#define HANGMANWIDGET_H

#include "ihangmanlogic.h"
#include <QWidget>

class HangmanWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HangmanWidget(IHangmanLogic *hl, QWidget *parent = nullptr);

private:
    IHangmanLogic *engine;

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
