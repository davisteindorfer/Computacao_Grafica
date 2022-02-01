#ifndef RAY_H
#define RAY_H

#include "Vector.hpp"

class Raio {
    private:
        Ponto orig;
        Vector dir;
    public:
        Raio() {}
        Raio(Ponto,Vector);
        Ponto get_origin();
        Vector get_direction();

        Ponto equacao_reta(double t);   
};

#endif