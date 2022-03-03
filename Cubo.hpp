#ifndef _CUBO_HPP
#define _CUBO_HPP
#include "Objeto.hpp"
#include "Raio.hpp"
#include <tuple>

class Cubo : public Objeto {
    public:
    Vector normal;
    Cubo(vector<Ponto>, vector<Aresta>, vector<Face>,Material, int);
    virtual Vector calcularNormal(Ponto* pi);
    virtual tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
};

#endif