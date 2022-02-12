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
#include "Material.hpp"
using namespace std;


class Objeto{
    public:
         vector<Ponto> Lista_De_Pontos;
         vector<Aresta> Lista_De_Aresta;
         vector<Face> Lista_De_Faces;
         Material material;
         int id;
    Objeto();
    Objeto(vector<Ponto>, vector<Aresta>, vector<Face>,Material, int);
    void set_lista_pontos(vector<Ponto>);
    void set_lista_arestas(vector<Aresta>);
    void set_lista_faces(vector<Face>);
    vector<Ponto> get_lista_pontos();
    vector<Aresta> get_lista_arestas();
    vector<Face> get_lista_faces();
    Vector calcularNormal(Ponto* pi);
};



#endif