#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include "Ponto.hpp"

#include "Vector.hpp"

#include "Objeto.hpp"
#include "operacoes.hpp"
#include <Eigen/Dense>

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