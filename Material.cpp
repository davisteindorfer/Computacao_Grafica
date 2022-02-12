#include "Material.hpp";

Material::Material() {}
Material::Material(vector<double> Ka1,vector<double> Kd1,vector<double> Ks1, double M){
    for(int i = 0; i < 3; i++){
        this->ka.push_back(Ka1[i]);
        this->kd.push_back(Kd1[i]);
        this->ks.push_back(Ks1[i]);
    }
    this->m = M;
}

vector<double> Material::Arroba(vector<double> v1, vector<double> v2){
    vector<double> result = vector<double> (3);
    for(int i = 0; i < 3; i++){
        result.push_back(v1[i]*v2[i]);
    }
};