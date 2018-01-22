//
// Created by krist on 22.01.2018.
//

#ifndef OPP1_DATE_H
#define OPP1_DATE_H

#include <iostream>

using namespace std;

class Date {
public:
    enum Month{JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

    Date(int day, int month, int year);
    Date(Date &date);
    ~Date() = default;;
    void addDay(int n);
    Date &operator+(int n);

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        Date::month = month;
    }

    int getDay() const;

    void setDay(int day);

    friend ostream& operator <<(ostream& os, const Date &date);

private:
    int year;
    int month;
    int day;
};


#endif //OPP1_DATE_H
