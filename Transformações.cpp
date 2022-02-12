#include <c++/math.h>
#include <Eigen/core>
#include "Transformações.hpp"

Ponto Transformações::Translação(Ponto p, Vector t){
    Eigen::Matrix4d matrizT;
    matrizT << 1, 0, 0, t.x,
               0, 1, 0, t.y,
               0, 0, 1, t.z,
               0, 0, 0, 1;
    Eigen::Matrix <double, 4, 1> MatrizP;
    MatrizP << p.x,
               p.y,
               p.z,
               1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
};

Vector Transformações::Translação(Vector p, Vector t){
    Eigen::Matrix4d matrizT;
    matrizT << 1, 0, 0, t.x,
               0, 1, 0, t.y,
               0, 0, 1, t.z,
               0, 0, 0, 1;
    Eigen::Matrix <double, 4, 1> MatrizP;
    MatrizP << p.x,
               p.y,
               p.z,
               0;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);
};

Ponto Transformações::Rotação(double theta, Ponto p, string eixo){

    if (eixo == "x"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, cos(theta), -(sin(theta)), 0,
                   0, sin(theta), cos(theta), 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);


    }

    if(eixo == "y"){
        Eigen::Matrix4d matrizT;
        matrizT << cos(theta), 0, sin(theta), 0,
                   0, 1, 0, 0,
                   -(sin(theta)), 0, cos(theta), 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);


    }
    if(eixo == "z"){
        Eigen::Matrix4d matrizT;
        matrizT << cos(theta), -(sin(theta)), 0, 0,
                   sin(theta), cos(theta), 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
        Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

        return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);


    }
}



Vector Transformações::Rotação(double theta, Vector p, string eixo){
if (eixo == "x"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, cos(theta), -(sin(theta)), 0,
                   0, sin(theta), cos(theta), 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);


    }

    if(eixo == "y"){
        Eigen::Matrix4d matrizT;
        matrizT << cos(theta), 0, sin(theta), 0,
                   0, 1, 0, 0,
                   -(sin(theta)), 0, cos(theta), 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);


    }
    if(eixo == "z"){
        Eigen::Matrix4d matrizT;
        matrizT << cos(theta), -(sin(theta)), 0, 0,
                   sin(theta), cos(theta), 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
        Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

        return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);

    }
}

Ponto Transformações::Escala(Ponto p, Vector t){
    Eigen::Matrix4d matrizT;
    matrizT << t.x, 0, 0, 0,
               0, t.y, 0, 0,
               0, 0, t.z, 0,
               0, 0, 0, 1;
    Eigen::Matrix <double, 4, 1> MatrizP;
    MatrizP << p.x,
               p.y,
               p.z,
               1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
}


Vector Transformações::Escala(Vector p, Vector t){
    Eigen::Matrix4d matrizT;
    matrizT << t.x, 0, 0, 0,
               0, t.y, 0, 0,
               0, 0, t.z, 0,
               0, 0, 0, 1;
    Eigen::Matrix <double, 4, 1> MatrizP;
    MatrizP << p.x,
               p.y,
               p.z,
               1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);
}


Ponto Transformações::Cisalhamento(double theta, Ponto p, string eixo){
    if (eixo == "x_horizontal"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, tan(theta), 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if(eixo == "x_vertical"){
        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   tan(theta), 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if(eixo == "y_horizontal" && "z_vertical"){
        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, 1, tan(theta), 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
        Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

        return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if (eixo == "y_vertical" && "z_horizontal"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, tan(theta), 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
}


Vector Transformações::Cisalhamento(double theta, Vector p, string eixo){
    if (eixo == "x_horizontal"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, tan(theta), 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);


    }

    if(eixo == "x_vertical"){
        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   tan(theta), 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);


    }
    if(eixo == "y_horizontal" && "z_vertical"){
        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, 1, tan(theta), 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
        Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

        return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);

    }
    if (eixo == "y_vertical" && "z_horizontal"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, tan(theta), 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
}
Ponto Transformações::Reflexão(Ponto p , string eixo){
    if (eixo == "x_y"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, -1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if(eixo == "x_z"){
        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, -1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if(eixo == "y_z"){
        Eigen::Matrix4d matrizT;
        matrizT << -1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
        Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

        return Ponto(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
}



Vector Transformações::Reflexão(Vector p , string eixo){
    if (eixo == "x_y"){

        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, -1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if(eixo == "x_z"){
        Eigen::Matrix4d matrizT;
        matrizT << 1, 0, 0, 0,
                   0, -1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
    Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

    return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
    if(eixo == "y_z"){
        Eigen::Matrix4d matrizT;
        matrizT << -1, 0, 0, 0,
                   0, 1, 0, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 1;
        Eigen::Matrix <double, 4, 1> MatrizP;
        MatrizP << p.x,
                   p.y,
                   p.z,
                   1;
        Eigen::Matrix <double, 4, 1> MatrizR = matrizT * MatrizP;

        return Vector(MatrizR[1],MatrizR[2],MatrizR[3]);
    }
}
