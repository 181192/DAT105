//
// Created by k on 19.02.18.
//

#include "Tull.h"

Tull::Tull(int tall) : tall(tall) {}

int Tull::getTall() const {
    return tall;
}

void Tull::setTall(int tall) {
    Tull::tall = tall;
}
