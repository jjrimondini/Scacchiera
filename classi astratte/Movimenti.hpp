#include <iostream>
#ifndef MOVIMENTI_HPP
#define MOVIMENTI_HPP
#include <array>
#include <vector>
#include <Posizione.hpp>
#include <Scacchiera.hpp>
#include <Controlli.hpp>
using namespace std;

class Movimenti{
	public:
        static void checkRiga (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse);
        static void checkColonna (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse);
        static void checkA (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse);
        static void checkB (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse);
        static void pedone (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse);
};

#endif