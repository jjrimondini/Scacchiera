#include <Controlli.hpp>


bool Controlli::checkC (int r){
	if (r>=0 && r<8)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Controlli::checkPosizione (Posizione p){
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