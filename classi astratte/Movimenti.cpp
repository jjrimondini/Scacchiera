#include <Movimenti.hpp>


	void Movimenti::checkRiga (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse) {
		
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

	void Movimenti::checkColonna (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
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

	void Movimenti::checkA (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
   		int r=p.riga;
   		int c=p.colonna;

   		for(int i=1;i<8;i++)
   		{
			int ri=r+i;
			int ci=c+i;
			if(Controlli::checkC(ri)==true && Controlli::checkC(ci)==true)
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
			if(Controlli::checkC(ri)==true && Controlli::checkC(ci)==true)
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

	 void Movimenti::checkB (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
   		int r=p.riga;
   		int c=p.colonna;

   		for(int i=1;i<8;i++)
   		{
			int ri=r+i;
			int ci=c-i;
			if(Controlli::checkC(ri)==true && Controlli::checkC(ci)==true)
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
			if(Controlli::checkC(ri)==true && Controlli::checkC(ci)==true)
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

	void Movimenti::pedone (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse)  {
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

void Movimenti::cavallo (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse){
	int r=p.riga;
	int c=p.colonna;
	const Pezzo* pezzo=s.getPezzo(r, c);
	Posizione p1={r+1,c+2};
	Pezzo* pezzoc=s.getPezzo(r+1, c+2);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r+1,c-2};
	pezzoc=s.getPezzo(r+1, c-2);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r-1,c+2};
	pezzoc=s.getPezzo(r-1, c+2);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r-1,c-2};
	pezzoc=s.getPezzo(r-1, c-2);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r+2,c-1};
	pezzoc=s.getPezzo(r+2, c-1);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r+2,c+1};
	pezzoc=s.getPezzo(r+2, c+1);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r-2,c-1};
	pezzoc=s.getPezzo(r-2, c-1);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
	p1={r-2,c+1};
	pezzoc=s.getPezzo(r-2, c+1);
	if(Controlli::checkPosizione(p1)==true && pezzoc==nullptr || pezzo->getColore()!=pezzoc->getColore())
	{
		mosse.push_back(p1);
	}
}