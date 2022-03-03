#ifndef _OBJETO_HPP
#define _OBJETO_HPP
#include "Face.hpp"
#include "Aresta.hpp"
#include "Ponto.hpp"
#include <iostream>
#include <vector>
#include "Material.hpp"
#include "Face.hpp"
#include <tuple>
using namespace std;


class Objeto{
    public:
         vector<Ponto> Lista_De_Pontos;
         vector<Aresta> Lista_De_Aresta;
         vector<Face> Lista_De_Faces;
         Material material;
         int id;
         string name;
    Objeto();
    Objeto(Material, int, string);
    Objeto(vector<Ponto>, vector<Aresta>, vector<Face>, Material, int);
    void set_lista_pontos(vector<Ponto>);
    void set_lista_arestas(vector<Aresta>);
    void set_lista_faces(vector<Face>);
    vector<Ponto> get_lista_pontos();
    vector<Aresta> get_lista_arestas();
    vector<Face> get_lista_faces();
    virtual Vector calcularNormal(Ponto* pi) {};
    virtual tuple<Ponto*,Objeto*> IntersecaoReta(Raio) {};
    
};



#endif