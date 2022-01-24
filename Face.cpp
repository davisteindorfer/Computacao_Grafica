#include "Face.hpp";
#include "Aresta.hpp";
#include "Aresta.cpp";

Face::Face(Aresta a1,Aresta a2,Aresta a3){
    this->aresta1 = a1;
    this->aresta2 = a2;
    this->aresta3 = a3;
};
void Face::set_aresta1(Aresta b1){
    aresta1 = b1;
};
void Face::set_aresta2(Aresta b2){
    aresta2 = b2;
};
void Face::set_aresta3(Aresta b3){
    aresta3 = b3;
};
Aresta Face::get_aresta1(){
    return aresta1;
};

Aresta Face::get_aresta2(){
    return aresta2;
};

Aresta Face::get_aresta3(){
    return aresta3;
};