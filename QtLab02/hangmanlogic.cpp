#include "hangmanlogic.h"
#include "QInputDialog"

HangmanLogic::HangmanLogic(QObject *parent) : QObject(parent)
{

}

void HangmanLogic::startNewGame(QString hiddenString)
{
    if (hiddenString.length() == 0)
        return;
    emit resetUi();

    hiddenMsg = hiddenString.toUpper();
    hiddenMsgScrambled = hiddenMsg.replace(QRegExp("[A-ZØÆÅ]"), "_");

    attemptNumber = 0;

    emit updateHiddenMessage(hiddenMsgScrambled);
    emit updateStatusMessage(QString("Attemps left: %1").arg(MAX_ATTEMPS-attemptNumber));
    emit updateAttemptsLeft(attemptNumber);

}

void HangmanLogic::restartGame()
{
    startNewGame(hiddenMsg);
}

void HangmanLogic::guess(QChar c)
{

}
