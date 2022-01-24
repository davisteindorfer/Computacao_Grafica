#ifndef Face_HPP;
#define Face_HPP;
#include "Aresta.hpp"
#include "Aresta.cpp"

class Face{
    private:
        Aresta aresta1,aresta2,aresta3;
    Face(Aresta,Aresta,Aresta);
    void set_aresta1(Aresta);
    void set_aresta2(Aresta);
    void set_aresta3(Aresta);
    Aresta get_aresta1();
    Aresta get_aresta2();
    Aresta get_aresta3();
};

#endif