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
    hiddenMsgScrambled = hiddenMsg;
    hiddenMsgScrambled.replace(QRegExp("[A-ZØÆÅ]"), "_");

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

    if (attemptNumber == MAX_ATTEMPS)
        return;

    if (QString(c)[0].isLetter() == false)
        return;

    QChar inputChar = QString(c).toUpper()[0];

    if (hiddenMsg.toLatin1().contains(inputChar.toLatin1())) {
        emit setButtonGreen(c);

        QString searchString = hiddenMsg;
        int index = 0;
        while( (index = searchString.indexOf(inputChar, index)) != -1 )
            hiddenMsgScrambled.replace(index++, 1, inputChar);

        emit updateHiddenMessage(hiddenMsgScrambled);

        if (hiddenMsgScrambled.contains("_") == false) {
            emit updateStatusMessage("You win!");
            emit gameOver();
            attemptNumber = MAX_ATTEMPS;
        }
    } else {
        emit setButtonRed(c);
        attemptNumber++;
        emit updateAttemptsLeft(attemptNumber);

        if (attemptNumber == MAX_ATTEMPS) {
            emit updateStatusMessage("You lose!");
            emit gameOver();
        } else {
            emit updateStatusMessage(QString("Attempts left: %1").arg(MAX_ATTEMPS-attemptNumber));
        }
    }

}
