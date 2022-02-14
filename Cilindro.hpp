#ifndef CILINDRO_HPP
#define CILINDRO_HPP
#include "operações.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"

class Cilindro : public Objeto{
public:
    double altura;
    double raio;
    Ponto centro;
    Ponto centroSup;
    Plano baseInf;
    Plano baseSup;
    Vector normal;
    Cilindro(double pAltura, double pRaio, Ponto pCentro, Vector pNormal, Material m, int);
    tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
    Ponto* PrimeiraIntersecao(Ponto &pP0, Vector &pVetor0);
    bool ValidacaoPontoLateral(Ponto &p_int);
    Vector calcularNormal(Ponto* pi);
};


#endif