#ifndef ESFERA_HPP
#define ESFERA_HPP
#include "operações.hpp"
#include "Objeto.hpp"
class Esfera : public Objeto {
public:
    string nome;
    float raio;
    Ponto* centro;
    Esfera(double Raio, Ponto* Centro);
    
};


#endif 