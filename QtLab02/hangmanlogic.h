#ifndef HANGMANLOGIC_H
#define HANGMANLOGIC_H

#include <QObject>
#include "hangmanlogic.h"

class HangmanLogic : public QObject
{
    Q_OBJECT

    QString hiddenMsg;
    QString hiddenMsgScrambled;
    const int MAX_ATTEMPS = 7;
    int attemptNumber;

public:
    explicit HangmanLogic(QObject *parent = nullptr);

    void init(QString hiddenString);
signals:
    void updateHiddenMessage(QString hiddenMsg);
    void updateStatusMessage(QString statusMsg);
    void updateAttemptsLeft(unsigned int attemptsLeft);
    void setButtonGreen(QChar c);
    void setButtonRed(QChar c);
    void resetUi(void);
    void gameOver(void);

public slots:
    void startNewGame(QString hiddenString);
    void restartGame();
    void guess(QChar c);
};

#endif // HANGMANLOGIC_H
