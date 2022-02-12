#ifndef Face_HPP;
#define Face_HPP;
#include "Aresta.hpp"
#include "Aresta.cpp"
#include "Plano.hpp"
#include "Vector.hpp"

class Face{
    public:
        Aresta p1p2,p2p3,p1p3;
    
    Face(Aresta,Aresta,Aresta);
    void set_aresta1(Aresta);
    void set_aresta2(Aresta);
    void set_aresta3(Aresta);
    Aresta get_p1p2();
    Aresta get_p2p3();
    Aresta get_p1p3();
    bool ValidacaoPontoFace(Vector,Vector ,Vector);
};

#endif