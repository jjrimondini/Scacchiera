#include <Alfiere.hpp>

Alfiere::Alfiere(Colore colore)
: Pezzo(colore){}
    

std::vector<Posizione> Alfiere::mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const {
   		std::vector<Posizione> mossePossibiliA;
		Movimenti::checkA (scacchiera, posizione, mossePossibiliA);
		Movimenti::checkB (scacchiera, posizione, mossePossibiliA);
   		return mossePossibiliA;
   	}