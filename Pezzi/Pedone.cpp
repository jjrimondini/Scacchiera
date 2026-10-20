#include <pedone.hpp>

Pedone::Pedone(Colore colore)
    	: Pezzo(colore){}

std::vector<Posizione> Pedone::mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const {
		std::vector<Posizione> mossePossibiliP;
		Movimenti::pedone(scacchiera, posizione, mossePossibiliP);
	}