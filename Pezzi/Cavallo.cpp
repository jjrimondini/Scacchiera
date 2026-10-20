#include <Cavallo.hpp>

Cavallo::Cavallo(Colore colore)
    	: Pezzo(colore){}

std::vector<Posizione> Cavallo::mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const
{
    std::vector<Posizione> mossePossibiliC;
    Movimenti::cavallo (scacchiera, posizione, mossePossibiliC);
}