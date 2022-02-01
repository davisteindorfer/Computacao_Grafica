#ifndef cubo_HPP;
#define cubo_HPP;
#include "Objeto.hpp";
#include "Objeto.cpp";
#include "Raio.cpp";

class Cubo : public Objeto {
    public:
    Cubo(vector<Ponto>, vector<Aresta>, vector<Face>);
    void intercessãoreta(Raio);
};

#endif