#ifndef _ESFERA_HPP
#define _ESFERA_HPP
#include "operacoes.hpp"
#include "Objeto.hpp"
#include <tuple>
class Esfera :public Objeto{
public:
    Esfera(double, Ponto*,Material, int);
    tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
    Vector calcularNormal(Ponto* pi);
};


#endif 