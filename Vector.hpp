#ifndef Vector_HPP;
#define Vector_HPP;
#include "Ponto.hpp";
#include "Ponto.cpp";
class Vector{
    private:
        double x;
        double y;
        double z;
    public:
    Vector(Ponto, Ponto);
    Vector(double, double, double);
    void set_x(double);
    void set_y(double);
    void set_z(double);
    double get_x();
    double get_y();
    double get_z();
    Vector operator+(Vector v);
    Vector operator*(Vector v);
    Vector operator-(Vector v);
    Vector operator/(Vector v);
};

#endif