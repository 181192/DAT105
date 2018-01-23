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

Transaksjon::Transaksjon(int fraId, int tilId, double belop) : fraId(fraId), tilId(tilId), belop(belop) {}

std::ostream &operator<<(std::ostream &os, const Transaksjon &transaksjon) {
    os << "fraId: " << transaksjon.fraId << " tilId: " << transaksjon.tilId << " belop: " << transaksjon.belop;
    return os;
}
