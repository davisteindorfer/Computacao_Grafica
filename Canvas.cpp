#include "Canvas.hpp"


Canvas::Canvas(int num_linhas,int num_colunas,double deltaX,double deltaY,double d,double altura,double largura){
    this->num_linhas = num_linhas;
    this->num_colunas = num_colunas;
    this->deltaX = deltaX;
    this->deltaY = deltaY;
    this->d = d;
    this->altura = altura;
    this->largura = largura;
}