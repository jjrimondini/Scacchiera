#ifndef PARTITA_H
#define PARTITA_H

#include <vector>
#include <array>
#include <Posizione.hpp>
#include <Scacchiera.hpp>
#include <memory>
#include "../Pezzi/Re.hpp"
#include "../Pezzi/Regina.hpp"
#include "../Pezzi/Torre.hpp"
#include "../Pezzi/Alfiere.hpp"
#include "../Pezzi/Cavallo.hpp"
#include "../Pezzi/Pedone.hpp"

class Partita {
	private:
    Scacchiera scacchiera;
    std::array<std::unique_ptr<Pezzo>, 32> pezzi;
	public:
			//  costruttore della partita
    Partita();

	
				//  funzione di movimento dei pezzi
	bool muoviPezzo (int ra, int ca, int rb, int cb);
		
			
	
};

#endif