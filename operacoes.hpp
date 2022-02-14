#ifndef _OPERACOES_HPP
#define _OPERACOES_HPP
#include "Vector.hpp"
#include "Aresta.hpp"
#include "Raio.hpp"
class operacoes {
    public:
    static double ProdutoEscalar(Vector, Vector);
    static Ponto* equacao_reta(double, Raio); 
    static Vector ProdutoVetorial(Vector,Vector);
    static Vector aresta_vetor(Aresta);
    static double distanciaEntrePontos(Ponto*, Ponto*);
    static Vector NormalizaVetor(Vector &vetor);
};


#endif