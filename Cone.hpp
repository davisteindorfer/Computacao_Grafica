#ifndef CONE_HPP
#define CONE_HPP
#include "operações.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"

class Cone : public Objeto{
public:
    double altura;
    double raio;
    Plano* base;
    Ponto centro;
    Vector normal;

    Cone(double pAltura, double pRaio, Ponto pCentro, Vector pNormal,Material m, int);
    bool ValidacaoPontoCone(Ponto* vertice, Ponto* p_int);
    tuple<Ponto*,Cone*> IntersecaoReta(Ponto*, Vector &pV0);
    Ponto* PrimeiraIntersecao(Ponto &pP0,Vector &pVetor0);
    Ponto* IntersecaoRetaBase(Ponto* centro, Ponto& pP0, Vector &pVetor0);
    Vector calcularNormal(Ponto* pi);
};

#endif