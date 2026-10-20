#include <Partita.hpp>


Partita::Partita()
    	: pezzi{
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
    		std::unique_ptr<Pedone>(new Pedone(Pezzo::Colore::nero))
		}
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

        }

    bool Partita::muoviPezzo (int ra, int ca, int rb, int cb)
		{
			if(Controlli::checkC(ra)==true && Controlli::checkC(rb)==true && Controlli::checkC(ca)==true && Controlli::checkC(cb)==true)
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

    