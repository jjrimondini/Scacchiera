#ifndef PEDONE_H
#define PEDONE_H

#include <Pezzo.hpp>
#include <Scacchiera.hpp>
#include <Movimenti.hpp>

class Pedone : public Pezzo {
	public:
	Pedone(Colore colore);

	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override ;
};

#endif