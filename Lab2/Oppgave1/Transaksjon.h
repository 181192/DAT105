//
// Created by krist on 23.01.2018.
//

#ifndef OPPGAVE1_TRANSAKSJON_H
#define OPPGAVE1_TRANSAKSJON_H


#include <ostream>

class Transaksjon {
public:
    int getFraId() const;

    void setFraId(int fraId);

    int getTilId() const;

    void setTilId(int tilId);

    double getBelop() const;

    void setBelop(double belop);

    Transaksjon(int fraId, int tilId, double belop);

    friend std::ostream &operator<<(std::ostream &os, const Transaksjon &transaksjon);

private:
    int fraId;
    int tilId;
    double belop;
};


#endif //OPPGAVE1_TRANSAKSJON_H
