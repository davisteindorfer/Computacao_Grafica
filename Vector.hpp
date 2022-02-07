#ifndef Vector_HPP;
#define Vector_HPP;
#include "Ponto.hpp";
#include "Ponto.cpp";
#include <cmath>
class Vector{
    public:
        double x;
        double y;
        double z;
    Vector();
    Vector(Ponto*, Ponto*);
    Vector(Ponto, Ponto);
    Vector(double, double, double);
    void set_x(double);
    void set_y(double);
    void set_z(double);
    double get_x();
    double get_y();
    double get_z();
    Vector operator+=(Vector v){
        this->x += v.get_x();
        this->y += v.get_y();
        this->z += v.get_z();
        return *this;
    }
    Vector operator*=(double constante){
        this->x *= constante;
        this->y *= constante;
        this->z *= constante;
        return *this;
    }
    Vector operator-(){
        this->x = -(this->x);
        this->y = -(this->y);
        this->z = -(this->z);
        return *this;
    };
    Vector operator/(double constante){
        this->x /= constante;
        this->y /= constante;
        this->z /= constante;
        return *this;
    }
    
};
inline Vector operator*(double t, Vector v) {
    return Vector(t*v.get_x(), t*v.get_y(), t*v.get_z());
}
inline Vector operator+(Vector u, Vector v) {
    return Vector(u.get_x() + v.get_x(), u.get_y() + v.get_y(), u.get_z() + v.get_z());
}
inline Ponto operator+(Ponto u, Vector v) {
    return Ponto(u.get_x() + v.get_x(), u.get_y() + v.get_y(), u.get_z() + v.get_z());
}
inline Vector operator-( Vector p1, Vector p2) {
    return Vector(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}
#endif