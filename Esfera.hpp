#ifndef ESFERA_HPP
#define ESFERA_HPP
#include "operações.hpp"
#include "Objeto.hpp"
#include <tuple>
class Esfera :public Objeto{
public:
    string nome;
    float raio;
    Ponto* centro;
    Esfera(double, Ponto*,Material, int);
    tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
    Vector calcularNormal(Ponto* pi);
};


#endif 