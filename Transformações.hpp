#ifndef transformações_HPP
#define transformações_HPP
#include "Vector.hpp"
#include <string>
using namespace std;

class Transformações{
    Ponto Translação(Ponto, Vector);
    Vector Translação(Vector, Vector);
    Ponto Escala(Ponto, Vector);
    Vector Escala(Vector, Vector);
    Ponto Rotação(double, Ponto, string);
    Vector Rotação(double, Vector, string);
    Ponto Cisalhamento(double, Ponto, string);
    Vector Cisalhamento(double, Vector, string);
    Ponto Reflexão (Ponto, string);
    Vector Reflexão (Vector, string);
};



#endif