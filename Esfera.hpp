#ifndef _ESFERA_HPP
#define _ESFERA_HPP
#include "operacoes.hpp"
#include "Objeto.hpp"
#include <tuple>
class Esfera :public Objeto{
public:
    double raio;
    Ponto centro;
    Esfera(double, Ponto*,Material, int);
    Vector calcularNormal(Ponto* pi);
    tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
};


#endif 