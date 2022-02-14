#ifndef _ARESTA_HPP
#define _ARESTA_HPP
#include "Ponto.hpp"


class Aresta{
    public:
        Ponto a,b;
        
    Aresta();
    Aresta(Ponto, Ponto);
    void set_a(Ponto);
    void set_b(Ponto);
    Ponto get_a();
    Ponto get_b();
};


#endif