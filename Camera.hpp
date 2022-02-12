#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "Ponto.hpp"
#include "Ponto.cpp"
#include "Vector.hpp"
#include "Vector.cpp"
#include "Objeto.hpp"
#include "Objeto.cpp"
#include <Eigen/core>

class Camera{
    public:
        Vector eye;
        Vector lookat;
        Vector viewup;
        Vector ic;
        Vector jc;
        Vector kc;
    Camera(Vector, Vector, Vector);
    Ponto Mundo_camera(Ponto);
    void atualizaCamera();
};

#endif