#ifndef Ponto_HPP;
#define Ponto_HPP;


class Ponto{
    public:
        double x,y,z;
    
    Ponto();
    Ponto(double, double, double);
    void set_x(double);
    void set_y(double);
    void set_z(double);
    double get_x();
    double get_y();
    double get_z();
    void operator+(Ponto p);
    void operator*(Ponto p);
    Ponto operator-(Ponto p);
    void operator/(Ponto p);

};

#endif