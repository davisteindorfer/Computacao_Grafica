#ifndef objeto_HPP;
#define objeto_HPP;
#include "Face.hpp"
#include "Face.cpp"
#include "Aresta.hpp"
#include "Aresta.cpp"
#include "Ponto.hpp"
#include "Ponto.cpp"
#include <iostream>
#include <vector>

using namespace std;
class Objeto{
    private:
         vector<Ponto> Lista_De_Pontos;
         vector<Aresta> Lista_De_Aresta;
         vector<Face> Lista_De_Faces;
    Objeto();
    Objeto(vector<Ponto>, vector<Aresta>, vector<Face>);
    void set_lista_pontos(vector<Ponto>);
    void set_lista_arestas(vector<Aresta>);
    void set_lista_faces(vector<Face>);
    vector<Ponto> get_lista_pontos();
    vector<Aresta> get_lista_arestas();
    vector<Face> get_lista_faces();
};



#endif