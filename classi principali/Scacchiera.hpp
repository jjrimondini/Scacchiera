#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include<Pezzo.hpp>

class Pezzo;

class Scacchiera {
	private:
			//  dichiaro i puntatori
	Pezzo*board[8][8];
	public:
			//  inizializzo la scacchiera vuota
	Scacchiera();
			//  funzione per inserire i pezzi tramite puntatore
	bool inserisciPezzo(Pezzo*pezzo, int riga, int colonna);
	
			//  funzione per trovare le coordinate di un pezzo
		Pezzo* getPezzo (int riga, int colonna) const;
	
			//  funzione per reimpostare una casella a nullptr
	bool rimuoviPezzo(int riga, int colonna);
};

#endif