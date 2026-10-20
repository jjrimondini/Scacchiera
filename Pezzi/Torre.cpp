#include <Torre.hpp>

Torre::Torre(Colore colore)	// costruttore
    	: Pezzo(colore)
    {
	}

std::vector<Posizione> Torre::mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const {
   		 std::vector<Posizione> mossePossibiliT;
		Movimenti::checkRiga (scacchiera, posizione, mossePossibiliT);
		Movimenti::checkColonna (scacchiera, posizione, mossePossibiliT);
   		return mossePossibiliT;	 
	}