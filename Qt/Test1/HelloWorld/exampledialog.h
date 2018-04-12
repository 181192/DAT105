#ifndef EXAMPLEDIALOG_H
#define EXAMPLEDIALOG_H

#include <QWidget>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#ifndef QT_NO_PRINTER
#include <QtPrintSupport/QPrinter>
#endif

class ExampleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ExampleDialog(QWidget *parent = nullptr);

signals:

public slots:
    void handlePrintButton();
private:
    QVBoxLayout *outerLayout;
    QRadioButton *rbtn1, *rbtn2, *rbtn3, *rbtn4;
    QPushButton *printBtn, *cancelBtn;
    QPrinter *printer;
    QComboBox *printerOptions;
    QTextEdit *textBox;

};
#endif // EXAMPLEDIALOG_H
