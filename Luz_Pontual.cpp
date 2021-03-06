#include <c++/cmath>
#include "Luz_Pontual.hpp"

Luz_Pontual::Luz_Pontual(vector<double> IA, vector<double> ID, vector<double> IE, Ponto posicaoLuz){
    for(int i = 0; i < 3; i++){
        this->intensidade_ambiente.push_back(IA[i]);
        this->intensidade_difusa.push_back(ID[i]);
        this->intensidade_especular.push_back(IE[i]);
    }
    this->posicao_luz = posicaoLuz;
}

double Luz_Pontual::calcular_Fator_Difuso(Ponto* ponto_intercecao, Vector normal){
    Vector aux = Vector(ponto_intercecao, &posicao_luz);
    Vector l = operacoes::NormalizaVetor(aux);

    double fatorDifuso = operacoes::ProdutoEscalar(normal, l);
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;
}

Vector Luz_Pontual::calcular_Intensidade_Difusa(Ponto* p, Material m, Vector normal){
    Vector Id;
    Id.x = intensidade_difusa[0] * m.kd[0];
    Id.y = intensidade_difusa[1] * m.kd[1];
    Id.z = intensidade_difusa[2] * m.kd[2];

    Id *= calcular_Fator_Difuso(p, normal);
    return Id;
}

double Luz_Pontual::calcularFatorEspecular(Ponto* ponto_intercecao, Vector normal){
    Vector aux = Vector(ponto_intercecao, &posicao_luz);
    Vector l = operacoes::NormalizaVetor(aux);

    Vector r = ((operacoes::ProdutoEscalar(l, normal)) * 2 * normal) - l;
    Vector v = Vector(ponto_intercecao, new Ponto(0,0,0));

    double fatorEspecular = operacoes::ProdutoEscalar(operacoes::NormalizaVetor(v),
        operacoes::NormalizaVetor(r));

    if(fatorEspecular < 0){
        return 0;
    }

    return fatorEspecular;
};

Vector Luz_Pontual::calcularIntensidadeEspecular(Ponto* p, Material m, Vector normal){
    Vector Is;
    Is.x = intensidade_especular[0] * m.ks[0];
    Is.y = intensidade_especular[1] * m.ks[1];
    Is.z = intensidade_especular[2] * m.ks[2];

    Is *=  pow(calcularFatorEspecular(p,normal), m.m);
    return Is;
};


