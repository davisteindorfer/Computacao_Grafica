#ifndef _LUZ_HPP
#define _LUZ_HPP
#include <vector>
using namespace std;
#include "Vector.hpp"
#include "Objeto.hpp"
class Luz{
    public:
    vector<double> intensidade_ambiente = vector<double> (3);
    vector<double> intensidade_difusa = vector<double> (3);
    vector<double> intensidade_especular = vector<double> (3);
    Luz();
    Luz(vector<double>, vector<double>, vector<double>);
    virtual Vector calcular_Intensidade_Difusa(Ponto*, Material, Vector) {};
    virtual Vector calcularIntensidadeEspecular(Ponto*, Material, Vector) {};
};

#endif