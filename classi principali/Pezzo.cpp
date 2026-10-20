#include<Pezzo.hpp>

   
Pezzo::Pezzo(Colore colore)
    	:colore(colore)
   		{
		}


Pezzo::~Pezzo()
{
}


Pezzo::Colore Pezzo::getColore()const{
    return colore;
}    