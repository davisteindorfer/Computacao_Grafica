#ifndef cubo_HPP;
#define cubo_HPP;
#include "Objeto.hpp";
#include "Objeto.cpp";
#include "Raio.cpp";
#include <tuple>

class Cubo : public Objeto {
    public:
    Vector normal;
    Cubo(vector<Ponto>, vector<Aresta>, vector<Face>,Material, int);
    tuple<Ponto*,Objeto*> intercessãoReta(Raio);
    Vector calcularNormal(Ponto* pi);
};

#endif