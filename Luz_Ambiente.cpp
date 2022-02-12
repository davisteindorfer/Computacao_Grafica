#include "Luz_Ambiente.hpp"


Luz_Ambiente::Luz_Ambiente(vector<double> IA, vector<double> ID, vector<double> IE){
    for(int i = 0; i < 3; i++){
        this->intensidade_ambiente.push_back(IA[i]);
        this->intensidade_difusa.push_back(ID[i]);
        this->intensidade_especular.push_back(IE[i]);
    }
}

vector<double> Luz_Ambiente::Intensidade_luz_ambiente(Material m){
    vector<double> Ia = vector<double> (3);
    Ia = m.Arroba(intensidade_ambiente, m.ka);
};