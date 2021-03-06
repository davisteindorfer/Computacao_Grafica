#include <c++/cmath>
#include "Luz_Spot.hpp"

Luz_Spot::Luz_Spot(vector<double> IA, vector<double> ID, vector<double> IE, Ponto posicao, Vector direcao, double angulo){
    for(int i = 0; i < 3; i++){
        this->intensidade_ambiente.push_back(IA[i]);
        this->intensidade_difusa.push_back(ID[i]);
        this->intensidade_especular.push_back(IE[i]);
    }
    this->posicao_luz = posicao;
    this->direcao = direcao;
    this->angulo = angulo;
}

double Luz_Spot::calcular_Fator_Difuso(Ponto* p, Vector normal) {
    Vector aux = Vector(p, &posicao_luz);
    Vector l = operacoes::NormalizaVetor(aux);
    if(operacoes::ProdutoEscalar(-l, direcao) > cos(angulo)){
        return 0 ;
    }
    double fatorDifuso = operacoes::ProdutoEscalar(l, normal);
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;
};

Vector Luz_Spot::calcular_Intensidade_Difusa(Ponto* p, Material m, Vector normal) {
    Vector Id;
    Id.x = intensidade_difusa[0] * m.kd[0];
    Id.y = intensidade_difusa[1] * m.kd[1];
    Id.z = intensidade_difusa[2] * m.kd[2];

    Id *= Luz_Spot::calcular_Fator_Difuso(p, normal);
    return Id;
}

double Luz_Spot::calcularFatorEspecular(Ponto* ponto_intercecao, Vector normal) {
    Vector aux = Vector(ponto_intercecao, &posicao_luz);
    Vector l = operacoes::NormalizaVetor(aux);

    Vector r = (2 * ((operacoes::ProdutoEscalar(l, normal))*normal)) - l;
    Vector v = Vector(ponto_intercecao, new Ponto(0,0,0));

    if(operacoes::ProdutoEscalar(-l, direcao) > cos(angulo)){
        return 0 ;
    }
    double fatorEspecular = operacoes::ProdutoEscalar(v, r);
    if(fatorEspecular < 0){
        return 0;
    }
    return fatorEspecular;

}

Vector Luz_Spot::calcularIntensidadeEspecular(Ponto* p, Material m, Vector normal){
    Vector Is;
    Is.x = intensidade_especular[0] * m.ks[0];
    Is.y = intensidade_especular[1] * m.ks[1];
    Is.z = intensidade_especular[2] * m.ks[2];

    Is *=  pow(calcularFatorEspecular(p,normal), m.m);
    return Is;
};
