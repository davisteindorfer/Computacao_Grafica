#include "Raio.hpp"

Raio::Raio(Ponto origem, Vector direcao){
    this->orig = origem;
    this->dir = direcao;
};

Ponto Raio::get_origin(){
    return orig;
}
Vector Raio::get_direction(){
    return dir;
}
Ponto Raio::equacao_reta(double t){
    return orig + t*dir;
}