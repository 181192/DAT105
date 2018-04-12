#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>


DbManager::DbManager(const QString& path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open())
        qWarning() << "Error: connection with database fail";
    else
        qInfo() << "Database: connection ok";
}

DbManager::~DbManager() {
    if (db.isOpen())
        db.close();
}

bool DbManager::isOpen() const {
    return db.isOpen();
}

bool DbManager::createTable() {
    bool success = true;

    QSqlQuery query;
    query.prepare("CREATE TABLE people(id INTEGER PRIMARY KEY, name TEXT);");

    if (!query.exec()) {
        qWarning() << "Couldn't create the table 'people': one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::addPerson(const QString& name) {
    bool success = false;

    if (name.isEmpty()) {
        qWarning() << "Add person failed: name cannot be empty";
        return success;
    }

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO people (name) VALUES (:name);");
    queryAdd.bindValue(":name", name);

    if (queryAdd.exec())
        success = true;
    else
        qWarning() << "Add person failed: " << queryAdd.lastError();

    return success;
}

bool DbManager::removePerson(const QString &name) {
    bool success = false;

    if (!personExists(name)) {
        qWarning() << "Remove person failed: person doesn't exist";
        return success;
    }

    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM people WHERE name = (:name);");
    queryDelete.bindValue(":name", name);
    success = queryDelete.exec();

    if (!success)
        qWarning() << "Remove person failed: " << queryDelete.lastError();

    return success;
}

void DbManager::printAllPersons() const {
    qInfo() << "Persons in db: ";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while(query.next()) {
        QString name = query.value(idName).toString();
        qInfo() << "===" << name;
    }
}

bool DbManager::personExists(const QString &name) const {
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM people WHERE name = (:name);");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec()) {
        if (checkQuery.next())
            exists = true;
    } else
         qWarning() << "person exists failed: " << checkQuery.lastError();

    return exists;
}

bool DbManager::removeAllPersons() {
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM people;");

    if (removeQuery.exec())
        success = true;
    else
        qWarning() << "remove all persons failed: " << removeQuery.lastError();

    return success;
}
