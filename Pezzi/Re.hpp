#ifndef RE_H
#define RE_H

#include <Pezzo.hpp>
#include <Scacchiera.hpp>
#include <Movimenti.hpp>


class Re : public Pezzo {
	public:
	Re(Colore colore);

	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override ;

};

#endif