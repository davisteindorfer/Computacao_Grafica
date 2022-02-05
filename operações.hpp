#ifndef operacoes_HPP;
#define operacoes_HPP;
#include "Vector.hpp"
#include "Aresta.hpp"
class operações {
    public:
    static double ProdutoEscalar(Vector v1, Vector v2);
    static Ponto* equacao_reta(double, Raio); 
    static Vector ProdutoVetorial(Vector,Vector);
    static Vector aresta_vetor(Aresta);
};


#endif