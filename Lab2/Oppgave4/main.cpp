#include <iostream>
#include "../../std_lib_facilities.h"


/**
 * Returnerer bit-verdien i posisjon k
 * @param n tall
 * @param k posisjon
 * @return bit-verdien i posisjon k
 */
int bitVerdiTilPosisjon(unsigned short n, int k) {
    return n & (1 << k);
}


/**
 * Teller antall bit som er satt til 1 i den binaere representasjonen av n
 * @param n tall
 * @return antall bit som er satt til 1
 */
int antallBitSattTilEn(unsigned short n) {
    if (n == 0)
        return 0;
    else
        return (n & 1) + antallBitSattTilEn(n >> 1);
}

/**
 * Finner hoyeste bit som er satt til 1 i den binaere representasjonen av n
 * @param n tall
 * @return hoyeste bit, ellers -1 hvis det ikke finnes noen 1'ere
 */
int hoyesteBitSattTilEn(unsigned short n) {
    return n == 0 ? -1 : 1 << (int) log2(n);
}

/**
 * Speilvender bitmonsteret til n
 * @param n
 * @return
 */
int speilvendBitmonsteret(unsigned short n) {
    unsigned int antallBits = sizeof(n) * 8 - 1;
    unsigned int revers = 0;

    for (int i = 0; i <= antallBits; i++)
        if (n & (1 << i))
            revers |= 1 << (antallBits - i);

    return revers;
}

/**
 * Sjekker om den binaere representasjonen av n er symmetrisk
 * @param n
 * @return true dersom den er symmetrisk, false ellers
 */
bool erSymmetrisk(unsigned short n) {
    return (n & speilvendBitmonsteret(n)) != 0;
}

/**
 * Finner antall bit satt til 1 i posisjon mindre enn et heltall k (til hoyre)
 * @param n tall
 * @param k posisjon
 * @return hoyeste bit ellers -1 hvis det ikke finnes noen 1'ere
 */
int hoyesteBitSattTilEnTilHoyreFor(unsigned short n, int k) {
    for (int i = k; i < sizeof(n)*8; i++)
        n &= ~(1 << i);
    return hoyesteBitSattTilEn(n);
}

/**
 * Finner antall bit satt til 1 i posisjon storre enn et heltall k (til venstre)
 * @param n tall
 * @param k posisjon
 * @return hoyeste bit ellers -1 hvis det ikke finnes noen 1'ere
 */
int hoyesteBitSattTilEnTilVenstreFor(unsigned short n, int k) {
    for (int i = 0; i <= k; i++)
        n &= ~(1 << i);
    return hoyesteBitSattTilEn(n);
}

int main() {
    unsigned short n = 170; // 010101010
    unsigned short j = 6;
    int k = 5;

    cout << bitVerdiTilPosisjon(n, k) << endl;
    cout << antallBitSattTilEn(n) << endl;
    cout << hoyesteBitSattTilEn(n) << endl;
    cout << speilvendBitmonsteret(n) << endl;
    cout << erSymmetrisk(n) << endl;
    cout << erSymmetrisk(j) << endl;
    cout << hoyesteBitSattTilEnTilHoyreFor(n, k) << endl;
    cout << hoyesteBitSattTilEnTilVenstreFor(n, k) << endl;

    return 0;
}