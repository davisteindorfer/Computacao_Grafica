#include "Luz_Ambiente.hpp"


Luz_Ambiente::Luz_Ambiente(vector<double> IA){
    for(int i = 0; i < 3; i++){
        this->intensidade_ambiente.push_back(IA[i]);
    }
}

vector<double> Luz_Ambiente::Intensidade_luz_ambiente(Material m){
    vector<double> Ia = vector<double> (3);
    Ia = m.Arroba(intensidade_ambiente, m.ka);
    return Ia;
};