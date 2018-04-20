#include <iostream>
#include "Spiller.h"


vector<Spiller> spillere;

void leggTilSpillere() {
    spillere.push_back(Spiller(0, "Peder", Konto(0, Konto::bitcoin)));
    spillere.push_back(Spiller(1, "Kristoffer-Andre", Konto(1, Konto::bitcoin)));
    spillere.push_back(Spiller(2, "Arne", Konto(2, Konto::bitcoin)));
}

int main() {
    cout << "Hello, World!" << endl;

    leggTilSpillere();
    for (Spiller &s : spillere) {
        cout << s.innskudd(1000) << endl;
    }

    spillere[0].betal(spillere[1], 50);
    spillere[1].betal(spillere[0], 50);
    spillere[2].betal(spillere[1], 50);
    spillere[0].betal(spillere[1], 50);
    spillere[1].betal(spillere[0], 50);
    spillere[2].betal(spillere[1], 50);
    spillere[0].betal(spillere[1], 50);
    spillere[1].betal(spillere[0], 50);
    spillere[2].betal(spillere[1], 50);

    cout << "\n***** Initial *****" << endl;
    cout << spillere[0].getBeholdning() << endl;
    cout << spillere[1].getBeholdning() << endl;
    spillere[0] + spillere[1];

    cout << "\n***** Etter + *****" << endl;
    cout << spillere[0].getBeholdning() << endl;
    cout << spillere[1].getBeholdning() << endl;
    cout << "\n***** Etter - *****" << endl;

    spillere[0] - spillere[1];
    cout << spillere[0].getBeholdning() << endl;
    cout << spillere[1].getBeholdning() << endl;


    cout << "***** Equals *****" << endl;
    cout << (&spillere[0] == &spillere[0]) << endl;
    cout << (&spillere[0] == &spillere[1]) << endl;


    cout << "***** Transaksjoner *****" << endl;
    char letter;
    ifstream reader("transaksjoner.txt");
    if (!reader) {
        cout << "Error opening file" << endl;
        return -1;
    }
    for (int i = 0; !reader.eof(); i++) {
        reader.get(letter);
        cout << letter;
    }

    cout << endl;
    reader.close();

    return 0;
}