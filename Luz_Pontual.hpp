#ifndef LuzPontual_HPP;
#define LuzPontual_HPP;
#include <vector>
using namespace std;
#include "Luz.hpp"
#include "Material.hpp"
#include "operações.hpp"
#include "Ponto.hpp"

class Luz_Pontual : public Luz {
    public:
    Ponto posição_luz;
    Luz_Pontual(vector<double>, vector<double>, vector<double>, Ponto);
    double calcular_Fator_Difuso(Ponto, Vector);
    Vector calcular_Intensidade_Difusa(Ponto, Material, Vector);
    double calcularFatorEspecular(Ponto, Vector);
    Vector calcularIntensidadeEspecular(Ponto, Material, Vector) ;
};
#endif