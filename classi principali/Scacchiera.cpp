#include <Scacchiera.hpp>
#include <Pezzo.hpp>

Scacchiera::Scacchiera(){
		for(int r=0;r<8;r++){
			for(int c=0;c<8;c++){
				board[r][c]=nullptr;
				}
			}
		}

bool Scacchiera::inserisciPezzo(Pezzo*pezzo, int riga, int colonna)
	{
		if(0<=riga && 0<=colonna && riga<8 && colonna<8)
		{
			board[riga][colonna]=pezzo;
			return true;
		}
		else
		{
			return false;
		}
	}

Pezzo* Scacchiera::getPezzo (int riga, int colonna) const {
			if(0<=riga && 0<=colonna && riga<8 && colonna<8)
			{
				return board[riga][colonna];
			}
			else
			{
				return nullptr;
			}
		}

bool Scacchiera::rimuoviPezzo(int riga, int colonna)
	{
		if(0<=riga && 0<=colonna && riga<8 && colonna<8)
		{
			board[riga][colonna]=nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}