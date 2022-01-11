#ifndef Ponto_HPP;
#define Ponto_HPP;

class Ponto{
    private:
        double x,y,z;
    public:
    Ponto(double, double, double);
    void set_x(double);
    void set_y(double);
    void set_z(double);
    double get_x();
    double get_y();
    double get_z();

};

#endif