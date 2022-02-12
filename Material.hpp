#ifndef Material_HPP;
#define Material_HPP;
#include "Vector.hpp";
#include <vector>;
using namespace std;
class Material{
    public:
    vector<double> ka = vector<double> (3);
    vector<double> kd = vector<double> (3);
    vector<double> ks = vector<double> (3);
    double m;
    Material();
    Material(vector<double>,vector<double>,vector<double>, double);
    vector<double> Arroba(vector<double>, vector<double>);
};

#endif