#ifndef _LUZ_SPOT_HPP
#define _LUZ_SPOT_HPP
#include <vector>
using namespace std;
#include "Luz.hpp"
#include "Material.hpp"
#include "operacoes.hpp"
#include "Ponto.hpp"

class Luz_Spot : public Luz{
    public:
    Ponto posicao_luz;
    Vector direcao;
    double angulo;
    Luz_Spot(vector<double>, vector<double>, vector<double>, Ponto, Vector, double);

    double calcular_Fator_Difuso(Ponto, Vector);
    Vector calcular_Intensidade_Difusa(Ponto, Material, Vector);
    double calcularFatorEspecular(Ponto, Vector);
    Vector calcularIntensidadeEspecular(Ponto, Material, Vector);
};


#endif