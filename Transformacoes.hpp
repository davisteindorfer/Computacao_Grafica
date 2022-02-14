#ifndef _TRANSFORMACOES_HPP
#define _TRANSFORMACOES_HPP
#include "Vector.hpp"
#include <string>
using namespace std;

class Transformacoes{
    Ponto Translacao(Ponto, Vector);
    Vector Translacao(Vector, Vector);
    Ponto Escala(Ponto, Vector);
    Vector Escala(Vector, Vector);
    Ponto Rotacao(double, Ponto, string);
    Vector Rotacao(double, Vector, string);
    Ponto Cisalhamento(double, Ponto, string);
    Vector Cisalhamento(double, Vector, string);
    Ponto Reflexao (Ponto, string);
    Vector Reflexao (Vector, string);
};



#endif