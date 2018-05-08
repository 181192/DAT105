#ifndef HANGMANWIDGET_H
#define HANGMANWIDGET_H

#include "hangmanlogic.h"
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
    explicit HangmanWidget(HangmanLogic *hl, QWidget *parent = nullptr);

private:
    HangmanLogic *engine;

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

    bool gameOverBool = true;

    QPixmap getHangmanImage(unsigned int num);

signals:
    void guessMade(QChar c);

public slots:
    void reset();
    void setHiddenMessage(QString msg);
    void setStatusMessage(QString msg);
    void buttonPressed();
    void setButtonGreen();
    void setButtonRed();
    void setAttemptsLeft(unsigned int attemptsLeft);
    void gameOver(void);
};

#endif // HANGMANWIDGET_H
