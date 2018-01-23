//
// Created by krist on 23.01.2018.
//

#ifndef OPPGAVE1_SPILLER_H
#define OPPGAVE1_SPILLER_H

#include "Konto.h"
#include "../../std_lib_facilities.h"

class Spiller {
public:

    const string &getNavn() const;

    void setNavn(const string &navn);

    double getBeholdning() const;

    Konto::Type getType() const;

    bool innskudd(double n);

    bool uttak(double n);

    Spiller(int id, string navn, Konto konto);

private:
    int id;
    string navn;
    Konto konto;

    bool sjekkDesimal(double n);

    bool betal(Spiller &spiller, double belop);
};


#endif //OPPGAVE1_SPILLER_H
