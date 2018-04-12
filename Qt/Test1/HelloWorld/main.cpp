#include "hellowidget.h"
#include "exampledialog.h"
#include "dbmanager.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    HelloWidget w;
    ExampleDialog e;
//    w.show();
    e.show();

//    DbManager db("peoplee.db");
//    if (!db.isOpen()) {
//        qWarning() << "Database is not open!";
//}

//        db.createTable();
//        db.addPerson("A");
//        db.addPerson("B");
//        db.addPerson("C");
//        db.printAllPersons();
//        db.removePerson("C");
//        db.printAllPersons();
////        db.removeAllPersons();
//        db.printAllPersons();
//        qInfo() << "End";


    return a.exec();
}
