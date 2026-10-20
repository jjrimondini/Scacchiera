#ifndef CAVALLO_H
#define CAVALLO_H

#include <Pezzo.hpp>
#include <Scacchiera.hpp>
#include <Movimenti.hpp>

class Cavallo : public Pezzo {
	public:
	Cavallo(Colore colore);
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override;
};

#endif