#ifndef PLANO_HPP
#define PLANO_HPP
#include "Vector.cpp"
#include "Raio.hpp"

class Plano {
public:
    Ponto p;
    Vector normal;

    Plano();
    Plano(Ponto, Vector);
    Ponto IntersecaoRaioPlano(Raio);
};


#endif 