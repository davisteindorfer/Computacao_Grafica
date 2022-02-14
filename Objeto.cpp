#include "Objeto.hpp"
#include <iostream>
#include <vector>


Objeto::Objeto() {}
Objeto::Objeto(vector<Ponto> lista_pontos, vector<Aresta> lista_arestas, vector<Face> lista_faces, Material m, int id){
    this->Lista_De_Pontos = lista_pontos;
    this->Lista_De_Aresta = lista_arestas;
    this->Lista_De_Faces = lista_faces;
    this->material = m;
    this->id = id;
};
void Objeto::set_lista_pontos(vector<Ponto> lista_pontos2){
    Lista_De_Pontos = lista_pontos2;
};
void Objeto::set_lista_arestas(vector<Aresta> lista_arestas2){
    Lista_De_Aresta = lista_arestas2;
};
void Objeto::set_lista_faces(vector<Face> lista_faces2){
    Lista_De_Faces = lista_faces2;
};
vector<Ponto> Objeto::get_lista_pontos(){
    return Lista_De_Pontos;
};
vector<Aresta> Objeto::get_lista_arestas(){
    return Lista_De_Aresta;
};
vector<Face> Objeto::get_lista_faces(){
    return Lista_De_Faces;
};