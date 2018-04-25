#ifndef HANGMANLOGIC_H
#define HANGMANLOGIC_H

#include <QObject>
#include "ihangmanlogic.h"

class HangmanLogic : public QObject, public IHangmanLogic
{
    Q_OBJECT
public:
    explicit HangmanLogic(QObject *parent = nullptr);

signals:
    void updateHiddenMessage(QString hiddenMsg);
    void updateStatusMessage(QString statusMsg);
    void updateAttemptsLeft(unsigned int attemptsLeft);

public slots:
    void startNewGame(QString hiddenString);
    void restartGame();
    void guess(char c);
};

#endif // HANGMANLOGIC_H
