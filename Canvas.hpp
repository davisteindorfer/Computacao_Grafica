#ifndef _CANVAS_HPP
#define _CANVAS_HPP
#include <vector>
using namespace std;

class Canvas{
    public:
    int num_linhas;
    int num_colunas;
    double deltaX;
    double deltaY;
    double d;
    double altura;
    double largura;
    Canvas(int,int ,double,double,double,double,double);

};

#endif