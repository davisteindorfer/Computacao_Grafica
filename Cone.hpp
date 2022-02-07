#ifndef CONE_HPP
#define CONE_HPP
#include "operações.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"

class Cone{
public:
    double altura;
    double raio;
    Plano* base;
    Ponto centro;
    Vector normal;

    Cone(double pAltura, double pRaio, Ponto pCentro, Vector pNormal);
    bool ValidacaoPontoCone(Ponto* vertice, Ponto* p_int);
    tuple<Ponto*, Cone*> IntersecaoReta(Ponto*, Vector &pV0);
    Ponto* PrimeiraIntersecao(Ponto &pP0,Vector &pVetor0);
    Ponto* IntersecaoRetaBase(Ponto* centro, Ponto& pP0, Vector &pVetor0);
};

#endif