#include "Ponto.hpp"
#include "Ponto.cpp"
#include "Vector.hpp"
#include "Vector.cpp"
#include "Objeto.hpp"
#include "Objeto.cpp"


class Camera{
    private:
        Ponto eye;
        Ponto lookat;
        Vector viewup;
    public:
    Camera(Ponto, Ponto, Vector);
    Objeto Mundo_camera(Objeto);
    void set_eye(Ponto);
    void set_lookat(Ponto);
    void set_viewup(Vector);
    Ponto get_eye();
    Ponto get_lookat();
    Vector get_viewup();
};