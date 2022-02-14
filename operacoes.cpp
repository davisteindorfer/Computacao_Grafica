#include "operacoes.hpp"
#include "Raio.hpp"
#include <c++/cmath>


double operacoes::ProdutoEscalar(Vector v1, Vector v2){
    return v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y() + v1.get_z() * v2.get_z();
}
Ponto* operacoes::equacao_reta(double t, Raio r){
    return new Ponto{r.orig.get_x() + t * r.get_direction().get_x(), r.orig.get_y() + t * r.get_direction().get_y(), r.orig.get_z() + t * r.get_direction().get_z()};
}
Vector operacoes::ProdutoVetorial(Vector v1,Vector v2){
    return {v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(), v1.get_z() * v2.get_x() - v1.get_x() * v2.get_z(), v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x()};
};
Vector operacoes::aresta_vetor(Aresta aresta){
    return Vector(aresta.b, aresta.a);
}
double operacoes::distanciaEntrePontos(Ponto* p1, Ponto* p2) {
    return sqrt(pow((p2->x - p1->x),2) + pow((p2->y - p1->y),2) + pow((p2->z - p1->z),2));
}
Vector operacoes::NormalizaVetor(Vector &vetor){
    return vetor/sqrt(ProdutoEscalar(vetor,vetor));
}