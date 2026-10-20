#ifndef PEZZO_H
#define PEZZO_H

#include <vector>
#include <Posizione.hpp>
#include <Scacchiera.hpp>

class Scacchiera;

class Pezzo {
	public:
			// enum class
   		 enum class Colore {
    		bianco,
    		nero
		};
			//  costruttore generico
   		 Pezzo(Colore colore);
    	

			//  funzioni di lettura dati
            // Colore getColore();
	Colore getColore() const;

	virtual ~Pezzo();
	
			//  funzione virtuale pura 
			//  controllo mosse possibili
	
	virtual std::vector<Posizione> mossePossibili (const Scacchiera& scacchiera, Posizione posizione) const =0;

		
	private:
			//  inizizlizzazione attributi
		Colore colore;
};

#endif