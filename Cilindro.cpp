#include <c++/cfloat>
#include <c++/cmath>
#include "Cilindro.hpp"
#include "Plano.hpp"
#include <tuple>


Cilindro::Cilindro(double pAltura, double pRaio, Ponto pCentro, Vector pNormal, Material m, int id){
    this->altura = pAltura;
    this->raio = pRaio;
    this->centro = pCentro;
    this->normal = pNormal;
    this->material = m;
    Vector H_n = normal;
    H_n *= altura;
    centroSup = Ponto{centro.x + H_n.x, centro.y + H_n.y, centro.z + H_n.z};
    baseSup = Plano(centroSup, normal);
    this->id = id;
    this->name = "Cilindro";
}

tuple<Ponto*,Objeto*> Cilindro::IntersecaoReta(Raio r){
    Ponto* pP0 = &r.orig;
    Vector pV0 = r.dir;
    Ponto* p_int1 = PrimeiraIntersecao(*pP0, pV0);
    return make_tuple(p_int1, this);
}

bool Cilindro::ValidacaoPontoLateral(Ponto &p_int) {
    Vector PB = Vector(centro, p_int);
    double PB_u = operacoes::ProdutoEscalar(PB, normal);

    return 0 <= PB_u && PB_u <= altura;
}

Ponto *Cilindro::PrimeiraIntersecao(Ponto &pP0, Vector &pVetor0) {
    // A*t_int² + 2B*t_int + C = 0

    // Normalizar o vetor_d
    auto vetorNorm = operacoes::NormalizaVetor(pVetor0);

    // C0P0 eh o P0 - C0
    Vector C0P0 = Vector(centro, pP0);

    // V eh o ((C0P0) - ((C0P0)* vetor_n)* vetor_n)
    Vector aux = normal;
    aux *= operacoes::ProdutoEscalar(C0P0, normal);
    Vector v = C0P0 - aux;

    // W eh o (pVetor0 - (pVetor0 * vetor_n)*vetor_n)
    aux = normal;
    aux *= operacoes::ProdutoEscalar(C0P0, normal);
    Vector w = vetorNorm - aux;

    //A = w*w
    double a = operacoes::ProdutoEscalar(w,w);

    //B = (v*w)
    double b = operacoes::ProdutoEscalar(v,w);

    //C = (v*v - R²)
    double c = operacoes::ProdutoEscalar(v,v) - (raio*raio);

    //delta
    double delta = b*b - a*c;
    /*  Δ > 0 tem 2 intersecoes
         Δ = 0 tem 1 intersecao
         Δ < 0 tem 0 intersecoes */

    if(delta < 0) return nullptr;

    double t_int1,t_int2;
    auto menorDistancia = DBL_MAX;

    // Intersecao com a base
    Ponto* p_int1 = baseInf.IntersecaoRaioPlano(Raio(pP0,pVetor0));
    if(p_int1) {
        if(operacoes::distanciaEntrePontos(p_int1, &centro) > raio){
            p_int1 = nullptr;
        } else {
            menorDistancia = operacoes::distanciaEntrePontos(&pP0, p_int1);
        }
    }

    // Intersecao com o topo
    Ponto* p_int2 = baseSup.IntersecaoRaioPlano(Raio(pP0,pVetor0));
    if(p_int2 && operacoes::distanciaEntrePontos(p_int2, &centroSup) <= raio) {
        double dist2 = operacoes::distanciaEntrePontos(p_int2, &pP0);
        if(!p_int1 || dist2 < menorDistancia) {
            p_int1 = p_int2;
            menorDistancia = dist2;
        }
    }

    // Intersecao com a lateral
    t_int1 = (-b + sqrt(delta))/a;
    t_int2 = (-b - sqrt(delta))/a;

    Ponto* p_teste1 = operacoes::equacao_reta(t_int1,Raio(pP0, vetorNorm));
    Ponto* p_teste2 = operacoes::equacao_reta(t_int2,Raio(pP0, vetorNorm));


    if (ValidacaoPontoLateral(*p_teste1)){
        double dist1 = operacoes::distanciaEntrePontos(p_teste1, &pP0);
        if(dist1 < menorDistancia) {
            p_int1 = p_teste1;
            menorDistancia = dist1;
        }
    }
    if (ValidacaoPontoLateral(*p_teste2)) {
        double dist2 = operacoes::distanciaEntrePontos(p_teste2, &pP0);
        if(dist2 < menorDistancia) {    
            p_int1 = p_teste2;
        }
    }

    return p_int1;
}
Vector Cilindro::calcularNormal(Ponto* pi){
    Vector PImenosCB = Vector(centro, *pi);
    double aux = operacoes::ProdutoEscalar(PImenosCB, normal);
    Vector aux2 = normal;
    aux2 *= aux;

    Ponto pe{centro.x + aux2.x, centro.y + aux2.y, centro.z + aux2.z};
    Vector PImenosPE = Vector(pe, *pi);

    Vector normalAoPonto = PImenosPE / raio;
    return normalAoPonto;
}