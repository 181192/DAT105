//
// Created by krist on 22.01.2018.
//
#include "Date.h"

Date::Date(int day, int month, int year) {
    Date::day = day;
    Date::month = month;
    Date::year = year;
}

Date::Date(Date &date) {
    year = date.year;
    month = date.month;
    day = date.day;
}

void Date::addDay(int n) {
    day += n;
}

Date &Date::operator+(int n) {
    Date *result = new Date(*this);
    result->addDay(n);
    return *result;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

ostream &operator<<(ostream &os, const Date &date) {
    return os << '(' << date.year
              << ',' << date.month
              << ',' << date.day
              << ')';
}
