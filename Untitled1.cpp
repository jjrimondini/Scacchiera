#include <iostream>
#include <array>
#include <vector>
#include <memory>
using namespace std;

struct Posizione {
    int riga;
    int colonna;
};

// funzione controllo coordinate
			
bool checkC (int r){
	if (r>=0 && r<8)
	{
		return true;
	}
	else
	{
		return false;
	}
}
			
//  funzione controllo posizione
			
bool checkPosizione (Posizione p){
	int r=p.riga;
	int c=p.colonna;
	if (r>=0 && r<8)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Scacchiera;

														//classe pezzo
class Pezzo {
	public:
			// enum class
   		 enum class Colore {
    		bianco,
    		nero
		};
			//  costruttore generico
   		 Pezzo(Colore colore)
    	:colore(colore)
   		{
		}

			//  funzioni di lettura dati
		Colore getColore()
		{

			return colore;
		}
	
	
			//  funzione virtuale pura 
			//  controllo mosse possibili
	
	virtual std::vector<Posizione> mossePossibili (const Scacchiera& scacchiera, Posizione posizione) const =0;

		
	private:
			//  inizizlizzazione attributi
		Colore colore;
};


														// classe scacchiera

class Scacchiera {
	private:
			//  dichiaro i puntatori
	Pezzo*board[8][8];
	public:
			//  inizializzo la scacchiera vuota
	Scacchiera(){
		for(int r=0;r<8;r++){
			for(int c=0;c<8;c++){
				board[r][c]=nullptr;
				}
			}
		}
			//  funzione per inserire i pezzi tramite puntatore
	bool inserisciPezzo(Pezzo*pezzo, int riga, int colonna)
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
			//  funzione per trovare le coordinate di un pezzo
		Pezzo* getPezzo (int riga, int colonna) const {
			if(0<=riga && 0<=colonna && riga<8 && colonna<8)
			{
				return board[riga][colonna];
			}
			else
			{
				return nullptr;
			}
		}
	
			//  funzione per reimpostare una casella a nullptr
	bool rimuoviPezzo(int riga, int colonna)
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
};

														// classe movimenti

class Movimenti{
	public:
	static void checkRiga (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse) {
		
		int r=p.riga;
   		int c=p.colonna;
   		for(int ci=c+1;ci<8;ci++)
   		{
   			if (s.getPezzo(r, ci)==nullptr)
   			{
   				Posizione p1={r, ci};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(r, ci);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={r, ci};
					mosse.push_back(p1);
					break;
				}
			}
		}
		for(int ci=c-1;ci>=0;ci--)
   		{
   			if (s.getPezzo(r, ci)==nullptr)
   			{
   				Posizione p1={r, ci};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(r, ci);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={r, ci};
					mosse.push_back(p1);
					break;
				}
			}
		}
	}

	static void checkColonna (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
		int r=p.riga;
   		int c=p.colonna;
   		for(int ri=r+1;ri<8;ri++)
   		{
   			if (s.getPezzo(ri, c)==nullptr)
   			{
   				Posizione p1={ri, c};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(ri, c);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={ri, c};
					mosse.push_back(p1);
					break;
				}
			}
		}
		for(int ri=r-1;ri>=0;ri--)
   		{
   			if (s.getPezzo(ri, c)==nullptr)
   			{
   				Posizione p1={ri, c};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(ri, c);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={ri, c};
					mosse.push_back(p1);
					break;
				}
			}
		}
	}

	static void checkA (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
   		int r=p.riga;
   		int c=p.colonna;

   		for(int i=1;i<8;i++)
   		{
			int ri=r+i;
			int ci=c+i;
			if(checkC(ri)==true && checkC(ci)==true)
			{
				if (s.getPezzo(ri, ci)==nullptr)
   			{
   				Posizione p1={ri, ci};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(ri, ci);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={ri, ci};
					mosse.push_back(p1);
					break;
				}
			}
			}
			else
			{
				break;
			}
		}
		for(int i=1;i<8;i++)
   		{
			int ri=r-i;
			int ci=c-i;
			if(checkC(ri)==true && checkC(ci)==true)
			{
				if (s.getPezzo(ri, ci)==nullptr)
   			{
   				Posizione p1={ri, ci};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(ri, ci);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={ri, ci};
					mosse.push_back(p1);
					break;
				}
			}
			}
			else
			{
				break;
			}
		}
   	}

	static void checkB (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
   		int r=p.riga;
   		int c=p.colonna;

   		for(int i=1;i<8;i++)
   		{
			int ri=r+i;
			int ci=c-i;
			if(checkC(ri)==true && checkC(ci)==true)
			{
				if (s.getPezzo(ri, ci)==nullptr)
   			{
   				Posizione p1={ri, ci};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(ri, ci);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={ri, ci};
					mosse.push_back(p1);
					break;
				}
			}
			}
			else
			{
				break;
			}
		}
		for(int i=1;i<8;i++)
   		{
			int ri=r-i;
			int ci=c+i;
			if(checkC(ri)==true && checkC(ci)==true)
			{
				if (s.getPezzo(ri, ci)==nullptr)
   			{
   				Posizione p1={ri, ci};
   				mosse.push_back(p1);
			}
			else
			{
				Pezzo* pezzo=s.getPezzo(r, c);
				Pezzo* pezzoc=s.getPezzo(ri, ci);
				if(pezzo->getColore()==pezzoc->getColore())
				{
					break;
				}
				else
				{
					Posizione p1={ri, ci};
					mosse.push_back(p1);
					break;
				}
			}
			}
			else
			{
				break;
			}
		}
   		
   	}

	static void pedone (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
		int r=p.riga;
		int c=p.colonna;
		int i;
			Pezzo* pezzo=s.getPezzo(r, c);
			if(pezzo->getColore()==Pezzo::Colore::nero){
				i=1;
			}
			if(pezzo->getColore()==Pezzo::Colore::bianco){
				i=-1;
			}
			Pezzo* pezzow=s.getPezzo(r+i, c);
			Pezzo* pezzoww=s.getPezzo(r+2*i, c);
			Pezzo* pezzoa=s.getPezzo(r+i, c-i);
			Pezzo* pezzod=s.getPezzo(r+i, c+i);
			if(pezzow==nullptr)
			{
				Posizione p1={r+i,c};
				mosse.push_back(p1);
			}
			if(pezzoww==nullptr && i==1  && r==1)
			{
				Posizione p1={r+2*i,c};
				mosse.push_back(p1);
			}
			if(pezzoww==nullptr && i==-1  && r==6)
			{
				Posizione p1={r+2*i,c};
				mosse.push_back(p1);
			}
			if(pezzoa!=nullptr && pezzoa->getColore()!=pezzo->getColore())
			{
				Posizione p1={r+i,c-i};
				mosse.push_back(p1);
			}
			if(pezzod!=nullptr && pezzod->getColore()!=pezzo->getColore())
			{
				Posizione p1={r+i,c+i};
				mosse.push_back(p1);
			}
	}
};

										// sottoclasse Re
class Re : public Pezzo {
	public:
	Re(Colore colore)
    	: Pezzo(colore)
    {
	}   
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override {}

};

										//  sottoclasse Regina
class Regina : public Pezzo {
	public:
	Regina(Colore colore)
    	: Pezzo(colore)
    {
    	
	}
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override {
		std::vector<Posizione> mossePossibiliQ;
		Movimenti::checkRiga (scacchiera, posizione, mossePossibiliQ);
		Movimenti::checkColonna (scacchiera, posizione, mossePossibiliQ);
		Movimenti::checkA (scacchiera, posizione, mossePossibiliQ);
		Movimenti::checkB (scacchiera, posizione, mossePossibiliQ);
		return mossePossibiliQ;
	}
};


										//  sottoclasse Torre
class Torre : public Pezzo {
	public:
	Torre(Colore colore)	// costruttore
    	: Pezzo(colore)
    {
	}
    						// mosse possibili
    std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override {
   		 std::vector<Posizione> mossePossibiliT;
		Movimenti::checkRiga (scacchiera, posizione, mossePossibiliT);
		Movimenti::checkColonna (scacchiera, posizione, mossePossibiliT);
   		return mossePossibiliT;	 
	}
	
};

										//  sottoclasse Alfiere
class Alfiere : public Pezzo {
	public:
	Alfiere(Colore colore)
    	: Pezzo(colore)
    {
    	
	}
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override {
   		std::vector<Posizione> mossePossibiliA;
		Movimenti::checkA (scacchiera, posizione, mossePossibiliA);
		Movimenti::checkB (scacchiera, posizione, mossePossibiliA);
   		return mossePossibiliA;
   	}
   	
   	private:
   	
};

										//  sottoclasse Cavallo
class Cavallo : public Pezzo {
	public:
	Cavallo(Colore colore)
    	: Pezzo(colore)
    {
	}
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override {}
};

										//  sottoclasse Pedone
class Pedone : public Pezzo {
	public:
	Pedone(Colore colore)
    	: Pezzo(colore)
    {	
	}
	std::vector<Posizione> mossePossibili(const Scacchiera& scacchiera, Posizione posizione) const override {
		std::vector<Posizione> mossePossibiliP;
		Movimenti::pedone(scacchiera, posizione, mossePossibiliP);
	}
};




	


														// classe Partita

class Partita {
	private:
    Scacchiera scacchiera;
    std::array<std::unique_ptr<Pezzo>, 32> pezzi;
	public:
			//  costruttore della partita
    Partita()
    	: pezzi({
    		std::unique_ptr<Re>(new Re(Pezzo::Colore::bianco)),
    		std::unique_ptr<Regina>(new Regina(Pezzo::Colore::bianco)),
    		std::unique_ptr<Torre>(new Torre(Pezzo::Colore::bianco)),
    		std::unique_ptr<Torre>(new Torre(Pezzo::Colore::bianco)),
    		std::unique_ptr<Alfiere>(new Alfiere(Pezzo::Colore::bianco)),
    		std::unique_ptr<Alfiere>(new Alfiere(Pezzo::Colore::bianco)),
    		std::unique_ptr<Cavallo>(new Cavallo(Pezzo::Colore::bianco)),
    		std::unique_ptr<Cavallo>(new Cavallo(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::bianco)),
    		std::unique_ptr<Re>(new Re(Pezzo::Colore::nero)),
    		std::unique_ptr<Regina>(new Regina(Pezzo::Colore::nero)),
    		std::unique_ptr<Torre>(new Torre(Pezzo::Colore::nero)),
    		std::unique_ptr<Torre>(new Torre(Pezzo::Colore::nero)),
    		std::unique_ptr<Alfiere>(new Alfiere(Pezzo::Colore::nero)),
    		std::unique_ptr<Alfiere>(new Alfiere(Pezzo::Colore::nero)),
    		std::unique_ptr<Cavallo>(new Cavallo(Pezzo::Colore::nero)),
    		std::unique_ptr<Cavallo>(new Cavallo(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero)),
		})
		{
			scacchiera.inserisciPezzo(pezzi[2].get(), 7, 0);
			scacchiera.inserisciPezzo(pezzi[6].get(), 7, 1);
			scacchiera.inserisciPezzo(pezzi[4].get(), 7, 2);
			scacchiera.inserisciPezzo(pezzi[1].get(), 7, 3);
			scacchiera.inserisciPezzo(pezzi[0].get(), 7, 4);
			scacchiera.inserisciPezzo(pezzi[5].get(), 7, 5);
			scacchiera.inserisciPezzo(pezzi[7].get(), 7, 6);
			scacchiera.inserisciPezzo(pezzi[3].get(), 7, 7);	
			for(int i=0;i<8;i++)
			{
				scacchiera.inserisciPezzo(pezzi[8+i].get(), 6, i);
			}	
			scacchiera.inserisciPezzo(pezzi[18].get(), 0, 0);
			scacchiera.inserisciPezzo(pezzi[22].get(), 0, 1);
			scacchiera.inserisciPezzo(pezzi[20].get(), 0, 2);
			scacchiera.inserisciPezzo(pezzi[17].get(), 0, 3);
			scacchiera.inserisciPezzo(pezzi[16].get(), 0, 4);
			scacchiera.inserisciPezzo(pezzi[21].get(), 0, 5);
			scacchiera.inserisciPezzo(pezzi[23].get(), 0, 6);
			scacchiera.inserisciPezzo(pezzi[19].get(), 0, 7);	
			for(int i=0;i<8;i++)
			{
				scacchiera.inserisciPezzo(pezzi[24+i].get(), 1, i);
			}	
	};
	
				//  funzione di movimento dei pezzi
			bool muoviPezzo (int ra, int ca, int rb, int cb)
			{
				if(checkC(ra)==true && checkC(rb)==true && checkC(ca)==true && checkC(cb)==true)
				{
					if(scacchiera.getPezzo(ra, ca)==nullptr)
					{
						cout <<"la casella di partenza non contiene pezzi";
						return false;
					}
					else
					{
						if(scacchiera.getPezzo(rb, cb)==nullptr)
						{
							Pezzo* pezzo = scacchiera.getPezzo(ra, ca);
							scacchiera.inserisciPezzo(pezzo, rb, cb);
							scacchiera.rimuoviPezzo(ra, ca);
							return true;
						}
						else
						{
							cout <<"la casella di destinazione contiene un pezzo";
							return false;
						}
					}
				}
				else
				{
					cout <<"una delle coordinate inserite � errata";
					return false;
				}
			}
			
			
	
				//  funzione di prova
	
			void provaposizione(int riga, int colonna){
   				 Pezzo* prova = scacchiera.getPezzo(riga, colonna);
   				 if (prova == nullptr) {
       			 std::cout << "Casella vuota o coordinate non valide\n";
   			}


    std::cout << "Colore: "
              << static_cast<int>(prova->getColore()) << "\n";
}
};



int main()
{
	int r=0, c=7;
	Partita partita;
	partita.provaposizione(r, c);
	
	
	return 0;	
}
