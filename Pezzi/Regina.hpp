#ifndef REGINA_H
#define REGINA_H

#include <Pezzo.hpp>
#include <Scacchiera.hpp>
#include <Movimenti.hpp>

class Regina : public Pezzo {
	public:
	Regina(Colore colore);

	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override ;
};

#endif