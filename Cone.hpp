#ifndef _CONE_HPP
#define _CONE_HPP
#include "operacoes.hpp"
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
    tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
    Ponto* PrimeiraIntersecao(Ponto &pP0,Vector &pVetor0);
    Ponto* IntersecaoRetaBase(Ponto* centro, Ponto& pP0, Vector &pVetor0);
    Vector calcularNormal(Ponto* pi);
};

#endif