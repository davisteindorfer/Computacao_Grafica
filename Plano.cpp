#include "Plano.hpp";
#include "Vector.hpp";
#include "operações.hpp";
Plano::Plano(){}
Plano::Plano(Ponto p1, Vector v){
    this->p = p1;
    this->normal = v;
};
Ponto Plano::IntersecaoRaioPlano(Ponto p2, Vector v1){
    //t_int = ( (P0 - Ppi) * n ) / (u*n)

    //vetor eh o Ppi - P0
    Vector *V = new Vector(p2, p);
    
}


