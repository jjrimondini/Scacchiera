#include <Scacchiera.hpp>
#include <Pezzo.hpp>
#include <Pedone.hpp>

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

bool verificaCasella (Posizione p, Pezzo::Colore coloreAttacco, const Scacchiera& s)
{
	for(int j=0;j<8;j++)
	{
		for(int h=0;h<8;h++)
		{
			Pezzo* pezzoc=s.getPezzo(j, h);
			if(pezzoc!=nullptr && pezzoc->getColore()==coloreAttacco)
			{
				if (dynamic_cast<const Pedone*>(pezzoc) != nullptr)
				{
					int i;
					if(pezzoc->getColore()==Pezzo::Colore::bianco)
					{
						i=-1;
					}
					else
					{
						i=1;
					}
					if(p.riga == j+i && (p.colonna == h+1 || p.colonna == h-1))
					{
						return true;
					}
				}
				else
				{
					Posizione pos {j, h};
					std::vector <Posizione> mosse = pezzoc->mossePossibili(s, pos);
					int dim=mosse.size();
					for(int k=0;k<dim;k++)
					{
						
						if(mosse[k].riga==p.riga && mosse[k].colonna==p.colonna)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}