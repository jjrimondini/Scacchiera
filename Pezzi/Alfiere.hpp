#ifndef ALFIERE_H
#define ALFIERE_H

#include <Pezzo.hpp>
#include <Scacchiera.hpp>
#include <Movimenti.hpp>

class Alfiere : public Pezzo {
	public:
	Alfiere(Colore colore);
    	
	
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override ;
   	
   	
   	
};

#endif