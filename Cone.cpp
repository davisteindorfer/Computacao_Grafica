#include <c++/cmath>
#include "Cone.hpp"
#include "Plano.hpp"
#include <tuple>
Cone::Cone(double pAltura, double pRaio, Ponto pCentro, Vector pNormal, Material m, int id) : altura(pAltura), raio(pRaio),
                                                                          centro(pCentro), normal(pNormal), Objeto(m,id,"cone"){
    base = new Plano(centro, normal);
};

tuple<Ponto*,Objeto*> Cone::IntersecaoReta(Raio r) {
    Ponto* pP0 = &r.orig;
    Vector pV0 = r.dir;
    static Ponto* p = Cone::PrimeiraIntersecao(*pP0, pV0);
    return make_pair(Cone::PrimeiraIntersecao(*pP0, pV0), this);
}

bool Cone::ValidacaoPontoCone(Ponto* vertice, Ponto* p_int){

    //escalar_tratamento e vetor_aux_tratamento
    Vector vetor_aux_tratamento(vertice->x - p_int->x, vertice->y - p_int->y, vertice->z - p_int->z);

    double escalar_tratamento = operacoes::ProdutoEscalar(vetor_aux_tratamento,this->normal);
    
    bool tratamento_int = false;
    if(escalar_tratamento < 0.00000000001 && escalar_tratamento > 0.00000000001)
        escalar_tratamento = 0;
    if(escalar_tratamento >= 0 && escalar_tratamento <= this->altura){
        tratamento_int = true;
    }

    return tratamento_int;
}

Ponto* Cone::IntersecaoRetaBase(Ponto* centro, Ponto& pP0, Vector &pVetor0){
    Raio r = Raio(pP0, pVetor0);
    Ponto* p_int = base->IntersecaoRaioPlano(r);
    return operacoes::distanciaEntrePontos(p_int,centro) <= raio? p_int : nullptr;
}


Ponto* Cone::PrimeiraIntersecao(Ponto &pP0,Vector &pVetor0) {
    //Vetor auxiliar para calcular o vertice do cone (H*n)
    Vector vetor_aux = normal;
    vetor_aux *= altura;
    

    Ponto vertice = Ponto(this->centro.x + vetor_aux.x, this->centro.y + vetor_aux.y,
        this->centro.z + vetor_aux.z);

    //vetor d normalizado
    Vector d = operacoes::NormalizaVetor(pVetor0);

    //cos alfa
    double cos_alfa = this->altura / (sqrt(pow(this->altura,2) + pow(raio,2)));

    //vetor v
    Vector v(vertice.x - pP0.x, vertice.y - pP0.y, vertice.z - pP0.z);

    //a
    double a = pow(operacoes::ProdutoEscalar(d,this->normal),2) - (operacoes::ProdutoEscalar(d,d)*pow(cos_alfa,2));

    //b
    double b = (operacoes::ProdutoEscalar(v,d) * pow(cos_alfa,2))
        - (operacoes::ProdutoEscalar(v,this->normal))
        * (operacoes::ProdutoEscalar(d,this->normal));

    //c
    double c1 = pow(operacoes::ProdutoEscalar(v,this->normal),2)
        - (operacoes::ProdutoEscalar(v,v)*pow(cos_alfa,2));

    //delta
    double delta = b*b - a*c1;

    if (delta < 0.00000000001 && delta >-0.00000000001 )
        delta = 0;
    if (a < 0.00000000001 && a>-0.00000000001)
        a = 0;
    if (b < 0.00000000001 && b>-0.00000000001)
        b = 0;
    if (c1 < 0.00000000001 && c1>-0.00000000001)
        c1 = 0;

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    double t_int1,t_int2;
    Ponto* p_int1 = nullptr;
    bool tratamento_int1 = false, tratamento_int2 = false;

    if (delta > 0){
        if(a!=0){
            t_int1 = (-b + sqrt(delta))/a;
            t_int2 = (-b - sqrt(delta))/a;
        }else{
            t_int1 = -c1 / 2*b;
            t_int2 = -c1 / 2*b;
        }
        
        Ponto* p_teste1 = operacoes::equacao_reta(t_int1,Raio(pP0,d));
        Ponto* p_teste2 = operacoes::equacao_reta(t_int2,Raio(pP0,d));
        tratamento_int1 = this->ValidacaoPontoCone(&vertice,p_teste1);
        tratamento_int2 = this->ValidacaoPontoCone(&vertice,p_teste2);

        if (tratamento_int1)
            p_int1 = p_teste1;
        else if((p_teste1 = Cone::IntersecaoRetaBase(&this->centro, pP0, d)) != nullptr)
            p_int1 = p_teste1;

        double p_int1_dis = p_int1 != nullptr ? operacoes::distanciaEntrePontos(p_int1, &pP0) : 0;

        if (tratamento_int2) {
            if(p_int1 == nullptr || operacoes::distanciaEntrePontos(p_teste2, &pP0) < p_int1_dis) {
                p_int1 = p_teste2;
            }
        }
        else if((p_teste2 = Cone::IntersecaoRetaBase(&this->centro, pP0, d)) != nullptr &&
            operacoes::distanciaEntrePontos(p_teste2, &pP0) < p_int1_dis){
            p_int1 = p_teste2;
        }

    }
    else if (delta == 0 && (b!=0 && a!=0)){
        t_int1 = (-b + sqrt(delta))/a;
        Ponto* p_teste1 = operacoes::equacao_reta(t_int1,Raio(pP0,d));
        tratamento_int1 = this->ValidacaoPontoCone(&vertice,p_teste1);

        if (tratamento_int1)
            p_int1 = p_teste1;
        if((p_teste1 = Cone::IntersecaoRetaBase(&this->centro, pP0, d)) != nullptr &&
            (p_int1 == nullptr || operacoes::distanciaEntrePontos(p_teste1, &pP0) < operacoes::distanciaEntrePontos(p_int1, &pP0))) {

            p_int1 = Cone::IntersecaoRetaBase(&this->centro, pP0, d);
        }

    }
    

    return p_int1;
}
Vector Cone::calcularNormal(Ponto* pi){
    Vector vetor_aux = normal;
    vetor_aux *= altura;

    Ponto* Vertice = new Ponto{centro.x + vetor_aux.x, centro.y + vetor_aux.y,
                                           centro.z + vetor_aux.z};

    Vector PImenosCB = Vector(centro, *pi);

    double aux = operacoes::ProdutoEscalar(PImenosCB, normal);
    Ponto* pe = operacoes::equacao_reta(aux, Raio(centro, normal));


    Vector PImenosPE = Vector(*pe, *pi);
    Vector PiV = Vector(*pi, *Vertice);

    Vector T = operacoes::ProdutoVetorial(PiV, PImenosPE);
    Vector N = operacoes::ProdutoVetorial(T, PiV);

    delete pe;
    delete Vertice;
    return operacoes::NormalizaVetor(N);
}