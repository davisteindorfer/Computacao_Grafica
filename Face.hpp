#ifndef Face_HPP;
#define Face_HPP;
#include "Aresta.hpp"
#include "Aresta.cpp"
#include "Plano.hpp"

class Face{
    public:
        Aresta aresta1,aresta2,aresta3;
        Plano plano1;
    Face(Aresta,Aresta,Aresta, Plano);
    void set_aresta1(Aresta);
    void set_aresta2(Aresta);
    void set_aresta3(Aresta);
    Aresta get_aresta1();
    Aresta get_aresta2();
    Aresta get_aresta3();
};

#endif