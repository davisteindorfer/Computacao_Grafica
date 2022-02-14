#ifndef _PLANO_HPP
#define _PLANO_HPP
#include "Vector.hpp"
#include "Raio.hpp"

class Plano {
public:
    Ponto p;
    Vector normal;

    Plano();
    Plano(Ponto, Vector);
    
    Ponto* IntersecaoRaioPlano(Raio);
};


#endif 