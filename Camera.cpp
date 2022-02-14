#include "Ponto.hpp"
#include "Vector.hpp"
#include "Objeto.hpp"
#include "Camera.hpp"


Camera::Camera(Vector eye, Vector lookat, Vector viewup){
    this->eye = eye;
    this->lookat = lookat;
    this->viewup = viewup;
    Vector aux = Vector(lookat, eye);
    kc = operacoes::NormalizaVetor(aux);
    aux = operacoes::ProdutoVetorial(Vector(eye, viewup),kc);
    ic = operacoes::NormalizaVetor(aux);
    jc = operacoes::ProdutoVetorial(kc,ic);
};
Ponto Camera::Mundo_camera(Ponto p){
    Eigen::Matrix4d matrizT;
    matrizT << ic.x, ic.y, ic.z, - operacoes::ProdutoEscalar(eye, ic),
               jc.x, jc.y, jc.z, - operacoes::ProdutoEscalar(eye, jc),
               kc.x, kc.y, kc.z, - operacoes::ProdutoEscalar(eye, kc),
               0, 0, 0, 1;
    Eigen::Matrix <double, 4, 1> MatrizP;
    MatrizP << p.x,
               p.y,
               p.z,
               1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
};

void Camera::atualizaCamera(){
    Vector aux = Vector(lookat, eye);
    kc = operacoes::NormalizaVetor(aux);
    aux = operacoes::ProdutoVetorial(Vector(eye, viewup),kc);
    ic = operacoes::NormalizaVetor(aux);
    jc = operacoes::ProdutoVetorial(kc,ic);
};
