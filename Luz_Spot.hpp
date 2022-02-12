#ifndef Luzspot_HPP;
#define Luzspot_HPP;
#include <vector>
using namespace std;
#include "Luz.hpp"
#include "Material.hpp"
#include "operações.hpp"
#include "Ponto.hpp"

class Luz_Spot : public Luz{
    public:
    Ponto posição_luz;
    Vector direção;
    double angulo;
    Luz_Spot(vector<double>, vector<double>, vector<double>, Ponto, Vector, double);

    double calcular_Fator_Difuso(Ponto, Vector);
    Vector calcular_Intensidade_Difusa(Ponto, Material, Vector);
    double calcularFatorEspecular(Ponto, Vector, Ponto);
    Vector calcularIntensidadeEspecular(Ponto, Material, Vector, Ponto) ;
};


#endif