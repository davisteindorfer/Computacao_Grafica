#ifndef CILINDRO_HPP
#define CILINDRO_HPP
#include "operações.hpp"
#include "Objeto.hpp"
// #include "PontoIntersecao.hpp"
#include "Plano.hpp"

class Cilindro : public Objeto{
public:
    string nome;
    float altura;
    float raio;
    Ponto centro;
    Ponto centroSup;
    Plano baseInf;
    Plano baseSup;
    Vetor normal;
    Cilindro(float pAltura, float pRaio, Ponto pCentro, Vetor pNormal, Material *m);
    tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
};


#endif