#ifndef _RAIO_HPP
#define _RAIO_HPP

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