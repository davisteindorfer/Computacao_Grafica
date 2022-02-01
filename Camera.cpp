#include "Ponto.hpp"
#include "Ponto.cpp"
#include "Vector.hpp"
#include "Vector.cpp"
#include "Objeto.hpp"
#include "Objeto.cpp"
#include "Camera.hpp"


Camera::Camera(Ponto eye, Ponto lookat, Vector viewup){
    this->eye = eye;
    this->lookat = lookat;
    this->viewup = viewup;
};
Objeto Camera::Mundo_camera(Objeto obj){
    
};