#ifndef TORRE_H
#define TORRE_H

#include <Pezzo.hpp>
#include <Scacchiera.hpp>
#include <Movimenti.hpp>

class Torre : public Pezzo {
	public:
	Torre(Colore colore);
    						// mosse possibili
    std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override ;
	
};
#endif