#ifndef Aresta_HPP;
#define Aresta_HPP;
#include "Ponto.hpp"
#include "Ponto.cpp"

class Aresta{
    private:
        Ponto a,b;
    public:    
    Aresta();
    Aresta(Ponto, Ponto);
    void set_a(Ponto);
    void set_b(Ponto);
    Ponto get_a();
    Ponto get_b();
};


#endif