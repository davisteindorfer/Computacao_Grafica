#include "Face.hpp";
#include "Aresta.hpp";
#include "Aresta.cpp";

Face::Face(Aresta a1,Aresta a2,Aresta a3){
    this->p1p2 = a1;
    this->p2p3 = a2;
    this->p3p1 = a3;
    
};
void Face::set_aresta1(Aresta b1){
    p1p2 = b1;
};
void Face::set_aresta2(Aresta b2){
    p2p3 = b2;
};
void Face::set_aresta3(Aresta b3){
    p3p1 = b3;
};
Aresta Face::get_aresta1(){
    return p1p2;
};

Aresta Face::get_aresta2(){
    return p2p3;
};

Aresta Face::get_aresta3(){
    return p3p1;
};