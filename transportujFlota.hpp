#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
if (towar == 0) return 0;

    Stocznia stocznia;
    unsigned int sumarycznyTransport = 0;
    unsigned int liczbaZaglowcow = 0;

    while (sumarycznyTransport < towar && sumarycznyTransport <= Stocznia::getTotalCap()) {
        Statek* statek = stocznia();  
        unsigned int transportowane = statek->transportuj();
        sumarycznyTransport += transportowane;

        if (dynamic_cast<Zaglowiec*>(statek)) {
            ++liczbaZaglowcow;
        }

        delete statek;
    }

    return liczbaZaglowcow;
}