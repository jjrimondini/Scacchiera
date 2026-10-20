#include <Regina.hpp>

Regina::Regina(Colore colore)
    	: Pezzo(colore){}

std::vector<Posizione> Regina::mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const {
		std::vector<Posizione> mossePossibiliQ;
		Movimenti::checkRiga (scacchiera, posizione, mossePossibiliQ);
		Movimenti::checkColonna (scacchiera, posizione, mossePossibiliQ);
		Movimenti::checkA (scacchiera, posizione, mossePossibiliQ);
		Movimenti::checkB (scacchiera, posizione, mossePossibiliQ);
		return mossePossibiliQ;
	}