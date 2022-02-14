#ifndef _OBJETO_HPP
#define _OBJETO_HPP
#include "Face.hpp"
#include "Aresta.hpp"
#include "Ponto.hpp"
#include <iostream>
#include <vector>
#include "Material.hpp"
#include "Face.hpp"
using namespace std;


class Objeto{
    public:
         vector<Ponto> Lista_De_Pontos;
         vector<Aresta> Lista_De_Aresta;
         vector<Face> Lista_De_Faces;
         Material material;
         int id;
         string name;
         double raio;
         Ponto* centro1;
         double altura;
         Plano* base;
         Ponto centro;
         Vector normal;
    Objeto();
    Objeto(vector<Ponto>, vector<Aresta>, vector<Face>, Material, int);
    void set_lista_pontos(vector<Ponto>);
    void set_lista_arestas(vector<Aresta>);
    void set_lista_faces(vector<Face>);
    vector<Ponto> get_lista_pontos();
    vector<Aresta> get_lista_arestas();
    vector<Face> get_lista_faces();
    Vector calcularNormal(Ponto* pi);
    tuple<Ponto*,Objeto*> IntersecaoReta(Raio);
};



#endif