#include "Luz.hpp"

Luz::Luz() {}
Luz::Luz(vector<double> IA,vector<double> ID,vector<double> IE){
    for(int i = 0; i < 3; i++){
        this->intensidade_ambiente.push_back(IA[i]);
        this->intensidade_difusa.push_back(ID[i]);
        this->intensidade_especular.push_back(IE[i]);
    }
}