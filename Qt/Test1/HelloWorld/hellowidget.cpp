#include "hellowidget.h"
#include <QLabel>

HelloWidget::HelloWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Hello, world!");
    this->setGeometry(100, 100, 300, 200);

    QLabel *hello_label = new QLabel(this);
    hello_label->setText("Hello, world!");
    hello_label->setGeometry(20, 20, 100, 20);

    btn1 = new QPushButton(this);
    btn2 = new QPushButton(this);

    btn1->setText("Hello");
    btn2->setText("World");

    btn1->setGeometry(20, 100, 100, 40);
    btn2->setGeometry(160, 100, 100, 40);


}
