#include <iostream>
#ifndef MOVIMENTIP_HPP
#define MOVIMENTIP_HPP
#include <array>
#include <vector>
#include <Posizione.hpp>
#include <Scacchiera.hpp>
#include <Controlli.hpp>
using namespace std;

class MovimentiP{
    public:
        static void movimentiP (const Scacchiera& s, Posizione p, std::vector<Posizione>& mosse);
};

#endif