#ifndef _RAYCASTING_HPP
#define _RAYCASTING_HPP

#include "Cenario.hpp"
#include "Camera.hpp"
#include "Canvas.hpp"

class RayCasting{
    public:
    static vector<vector<vector<double>>> Ray_Casting(Cenario, Ponto, Canvas, Luz_Ambiente);
};

#endif

