#include <iostream>
#ifndef CONTROLLI_HPP
#define CONTROLLI_HPP

#include <Posizione.hpp>
using namespace std;

class Controlli{
	public:
        static bool checkC (int r);
        static bool checkPosizione (Posizione p);
};

#endif