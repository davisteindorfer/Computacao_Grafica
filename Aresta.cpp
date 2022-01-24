#include "Aresta.hpp";
#include "Ponto.hpp";
#include "Ponto.cpp";


Aresta::Aresta(){};
Aresta::Aresta(Ponto a1, Ponto b1){
    this->a = a1;
    this->b = b1;
};
void Aresta::set_a(Ponto a2){
    a = a2;
};
void Aresta::set_b(Ponto b2){
    b = b2;
};
Ponto Aresta::get_a(){
    return a;
};
Ponto Aresta::get_b(){
    return b;
};    
