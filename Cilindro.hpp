#ifndef CILINDRO_HPP
#define CILINDRO_HPP
#include "operações.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"

class Cilindro{
public:
    double altura;
    double raio;
    Ponto centro;
    Ponto centroSup;
    Plano baseInf;
    Plano baseSup;
    Vector normal;
    Cilindro(double pAltura, double pRaio, Ponto pCentro, Vector pNormal);
    tuple<Ponto*,Cilindro*> IntersecaoReta(Ponto* pP0, Vector &pV0);
    Ponto* PrimeiraIntersecao(Ponto &pP0, Vector &pVetor0);
    bool ValidacaoPontoLateral(Ponto &p_int);
};


#endif