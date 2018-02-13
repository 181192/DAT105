//
// Created by krist on 23.01.2018.
//

#include "Transaksjon.h"

int Transaksjon::getFraId() const {
    return fraId;
}

void Transaksjon::setFraId(int fraId) {
    Transaksjon::fraId = fraId;
}

int Transaksjon::getTilId() const {
    return tilId;
}

void Transaksjon::setTilId(int tilId) {
    Transaksjon::tilId = tilId;
}

double Transaksjon::getBelop() const {
    return belop;
}

void Transaksjon::setBelop(double belop) {
    Transaksjon::belop = belop;
}

const string &Transaksjon::getFilnavn() const {
    return filnavn;
}

void Transaksjon::setFilnavn(const string &filnavn) {
    Transaksjon::filnavn = filnavn;
}

Transaksjon::Transaksjon(int fraId, int tilId, double belop, string filnavn) : fraId(fraId), tilId(tilId), belop(belop), filnavn(filnavn) {
    ofstream writer(filnavn, ios::app);
    if (! writer)
    {
        cout << "Error opening file" << endl;
    }
    writer << *this << endl;
    writer.close();
}

std::ostream &operator<<(std::ostream &os, const Transaksjon &transaksjon) {
    os << "fraId: " << transaksjon.fraId << " tilId: " << transaksjon.tilId << " belop: " << transaksjon.belop;
    return os;
}
