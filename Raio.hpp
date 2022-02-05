#ifndef RAY_H
#define RAY_H

#include "Vector.hpp"

class Raio {
    public:
        Ponto orig;
        Vector dir;
        Raio() {}
        Raio(Ponto,Vector);
        Ponto* get_origin();
        Vector get_direction();

        Ponto* equacao_reta(const double &t);   
};

#endif