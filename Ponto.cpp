#include "Ponto.hpp"

Ponto::Ponto() {}
Ponto::Ponto(double x1, double y1, double z1) {
    this->x = x1;
    this->y = y1;
    this->z = z1;
};
void Ponto::set_x(double x2) {
    x = x2;
};
void Ponto::set_y(double y2) {
    y = y2;
};
void Ponto::set_z(double z2) {
    z = z2;
};

double Ponto::get_x(){
    return x;
};
double Ponto::get_y(){
    return y;
};
double Ponto::get_z(){
    return z;
};
void Ponto::operator+(Ponto p){
    this->x = this->x + p.x;
    this->y = this->y + p.y;
    this->z = this->z + p.z;
};


