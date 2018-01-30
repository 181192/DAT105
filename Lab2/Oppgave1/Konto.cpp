//
// Created by krist on 23.01.2018.
//

#include "Konto.h"

Konto::Konto(int id, Konto::Type type) : id(id), beholdning(0), type(type) {}

double Konto::getBeholdning() const {
    return beholdning;
}

Konto::Type Konto::getType() const {
    return type;
}

bool Konto::uttak(double n) {
    return (n < 0 && beholdning < n) ? false : (beholdning -= n), true;
}

bool Konto::innskudd(double n) {
    return (n < 0) ? false : (beholdning += n), true;
}

std::ostream &operator<<(std::ostream &os, const Konto &konto) {
    os << "id: " << konto.id << " beholdning: " << konto.beholdning << " type: " << konto.type;
    return os;
}


