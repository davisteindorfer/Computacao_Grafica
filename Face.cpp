#include "Face.hpp"
#include "Aresta.hpp"
#include "Aresta.cpp"
#include "operações.hpp"

Face::Face(Aresta a1,Aresta a2,Aresta a3){
    this->p1p2 = a1;
    this->p2p3 = a2;
    this->p1p3 = a3;
    
};
void Face::set_aresta1(Aresta b1){
    p1p2 = b1;
};
void Face::set_aresta2(Aresta b2){
    p2p3 = b2;
};
void Face::set_aresta3(Aresta b3){
    p1p3 = b3;
};
Aresta Face::get_p1p2(){
    return p1p2;
};

Aresta Face::get_p2p3(){
    return p2p3;
};

Aresta Face::get_p1p3(){
    return p1p3;
};
bool Face::ValidacaoPontoFace(Vector P1P,Vector P2P,Vector P3P){
    Vector p1_p2 = Vector(p1p2.a, p1p2.b);
    Vector p2_p3 = Vector(p2p3.a, p2p3.b);
    Vector p1_p3 = Vector(p1p3.a, p1p3.b);
    double validacao = operações::ProdutoEscalar(operações::ProdutoVetorial(p1_p2, P1P),
                                                  operações::ProdutoVetorial(p1_p2, p1_p3));
    if(validacao < 0){
        return false;
    }

    validacao = operações::ProdutoEscalar(operações::ProdutoVetorial(p2_p3, P2P),
                                                  operações::ProdutoVetorial(p1_p2, p1_p3));
    if(validacao < 0){
        return false;
    }

    validacao = operações::ProdutoEscalar(operações::ProdutoVetorial(p1_p3, P3P),
                                           operações::ProdutoVetorial(p1_p2, p1_p3));

    return validacao > 0;
};
