#include "Esfera.hpp"
#include <tuple>

Esfera::Esfera(double Raio, Ponto* Centro,Material m, int id){
    this->raio = Raio;
    this->centro = Centro;
    this->material = m;
    this->id = id;
};
tuple<Ponto*,Esfera*> Esfera::IntersecaoReta(Ponto* pP0, Vector pV0){
    Ponto* p_t_int1 = nullptr;
    Ponto* p_t_int2 = nullptr;
    double t_int1, t_int2;
    // A*t_int² + B*t_int + C = 0
    Vector pV0N = operações::NormalizaVetor(pV0);
    // C0P0 eh o P0 - C0
    Vector C0P0 = Vector(*this->centro, *pP0);
    // A = u*u
    double produtoA = operações::ProdutoEscalar(pV0N,pV0N);
    // B = 2 * (P0 - C0) * u
    double produtoB = operações::ProdutoEscalar(C0P0,pV0N);
    // C = (P0 - C0) * (P0 - C0) - R²
    double produtoC = operações::ProdutoEscalar(C0P0,C0P0) - (this->raio*this->raio);
    /*  se Δ > 0, 2 intersecoes
        se Δ = 0, 1 intersecao
        se Δ < 0, 0 intersecoes */
    double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);
    if (Delta > 0){

        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        t_int2 = (-produtoB - sqrt(Delta))/produtoA;
        p_t_int1 = operações::equacao_reta(t_int1,Raio(*pP0,pV0N));
        p_t_int2 = operações::equacao_reta(t_int2,Raio(*pP0,pV0N));
        if(operações::distanciaEntrePontos(p_t_int1,pP0) > operações::distanciaEntrePontos(p_t_int2,pP0)) {
            p_t_int1 = p_t_int2;
        }
    }
    else if (Delta == 0){

        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        p_t_int1 = operações::equacao_reta(t_int1,Raio(*pP0,pV0N));
    }

    return make_tuple(p_t_int1, this);

}

Vector Esfera::calcularNormal(Ponto* p){
    Vector v;
    v = Vector(*this->centro,*p);
    v = operações::NormalizaVetor(v);
    return v;
}
