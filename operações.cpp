#include "operações.hpp";
#include "Raio.hpp";


double operações::ProdutoEscalar(Vector v1, Vector v2){
    return v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y() + v1.get_z() * v2.get_z();
}
Ponto* operações::equacao_reta(double t, Raio r){
    return new Ponto{r.get_origin().get_x() + t * r.get_direction().get_x(), r.get_origin().get_y() + t * r.get_direction().get_y(), r.get_origin().get_z() + t * r.get_direction().get_z()};
}
Vector operações::ProdutoVetorial(Vector v1,Vector v2){
    return {v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(), v1.get_z() * v2.get_x() - v1.get_x() * v2.get_z(), v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x()};
};
Vector operações::aresta_vetor(Aresta aresta){
    return Vector(aresta.b, aresta.a);
}