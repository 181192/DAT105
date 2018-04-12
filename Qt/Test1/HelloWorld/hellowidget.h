#ifndef HELLOWIDGET_H
#define HELLOWIDGET_H

#include <QWidget>
#include <QPushButton>

class HelloWidget : public QWidget
{
    Q_OBJECT
    QPushButton *btn1, *btn2;

public:
    explicit HelloWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // HELLOWIDGET_H
