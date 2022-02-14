#ifndef Luz_HPP;
#define Luz_HPP;
#include <vector>
using namespace std;

class Luz{
    public:
    vector<double> intensidade_ambiente = vector<double> (3);
    vector<double> intensidade_difusa = vector<double> (3);
    vector<double> intensidade_especular = vector<double> (3);
    Luz();
    Luz(vector<double>, vector<double>, vector<double>);
    Vector calcular_Intensidade_Difusa(Ponto, Material, Vector);
    Vector calcularIntensidadeEspecular(Ponto, Material, Vector);
};

#endif;