#include "Plano.hpp"
#include "Vector.hpp"
#include "operacoes.hpp"
Plano::Plano(){}
Plano::Plano(Ponto p1, Vector v){
    this->p = p1;
    this->normal = v;
};
Ponto* Plano::IntersecaoRaioPlano(Raio r1){

    Vector *V = new Vector(r1.orig, p);
    double produto = operacoes::ProdutoEscalar(*V, normal);
    double produto1 = operacoes::ProdutoEscalar(r1.get_direction(), normal);

    if(produto1 == 0){
        return nullptr;
    }
    double t_int = produto/produto1;

    return operacoes::equacao_reta(t_int,r1);

}


