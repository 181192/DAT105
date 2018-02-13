//
// Created by krist on 23.01.2018.
//

#include "Spiller.h"

int Spiller::getId() const {
    return id;
}

const string &Spiller::getNavn() const {
    return navn;
}

void Spiller::setNavn(const string &navn) {
    Spiller::navn = navn;
}

double Spiller::getBeholdning() const {
    return konto.getBeholdning();
}

Konto::Type Spiller::getType() const {
    return konto.getType();
}


const Vector<Transaksjon> &Spiller::getTransaksjoner() const {
    return transaksjoner;
}

Spiller::Spiller(int id, string navn, Konto konto)
        : id(id), navn(navn), konto(konto) {
    vector<Transaksjon> *transaksjoner = new vector<Transaksjon>();
}

/**
 * Returnerer true hvis antall desimaler er under 8
 */
bool Spiller::sjekkDesimal(double n) {
    return fmod(n * 100000000, 1) == 0;
}

bool Spiller::innskudd(double n) {
    if (konto.getType() == Konto::bitcoin) {
        return sjekkDesimal(n) && konto.innskudd(n);
    }
    return konto.innskudd(n);
}

bool Spiller::uttak(double n) {
    if (konto.getType() == Konto::bitcoin) {
        return sjekkDesimal(n) && konto.uttak(n);
    }
    return konto.uttak(n);
}

bool Spiller::betal(Spiller &spiller, double belop) {
    return konto.getType() == spiller.getType()
           && uttak(belop)
           && (transaksjoner.push_back(Transaksjon(id, spiller.getId(), belop, "transaksjoner.txt")),
            spiller.innskudd(belop));
}

ostream &operator<<(ostream &os, const Spiller &spiller) {
    os << "id: " << spiller.id << ", navn: " << spiller.navn << ", konto: { " << spiller.konto << " }";
    return os;
}

void Spiller::operator+(Spiller &spiller) {
    Spiller::betal(*this, spiller.getBeholdning());
}

void Spiller::operator-(Spiller &spiller) {
    Spiller::betal(spiller, getBeholdning());
}

bool Spiller::operator==(const Spiller &spiller) {
    return id == spiller.id && navn.compare(spiller.navn) && konto == spiller.konto;
}

