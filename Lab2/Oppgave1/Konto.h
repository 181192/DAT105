//
// Created by krist on 23.01.2018.
//

#ifndef OPPGAVE1_KONTO_H
#define OPPGAVE1_KONTO_H


#include <ostream>
#include "../../std_lib_facilities.h"

class Konto {
public:

    enum Type {
        bitcoin, hackos, gullmynt
    };

    bool innskudd(double n);

    bool uttak(double n);

    Konto(int id, Type type);

    ~Konto() = default;

    double getBeholdning() const;

    Type getType() const;

    friend ostream &operator<<(ostream &os, const Konto &konto);
    bool operator==(Konto konto);

private:
    int id;
    double beholdning;
    Type type;
};


#endif //OPPGAVE1_KONTO_H
