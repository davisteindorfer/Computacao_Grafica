#include "Ponto.hpp";
#include "Ponto.cpp";
#include "Vector.hpp";

Vector::Vector(){}
Vector::Vector(Ponto p1, Ponto p2){
    
    this->x = (p2-p1).get_x();
    this->y = (p1-p2).get_y();
    this->z = (p1-p2).get_z();
};

Vector::Vector(double x1, double y1, double z1){
    this->x = x1;
    this->y = y1;
    this->z = z1;
};

void Vector::set_x(double x2) {
    x = x2;
};
void Vector::set_y(double y2) {
    y = y2;
};
void Vector::set_z(double z2) {
    z = z2;
};

double Vector::get_x(){
    return x;
};
double Vector::get_y(){
    return y;
};
double Vector::get_z(){
    return z;
};
Vector operator+(Vector v){

}
Vector operator*(Vector v){

}
Vector operator-(){
    this->x = -(this->x);
    this->y = -(this->y);
}
Vector operator/(Vector v){

}

