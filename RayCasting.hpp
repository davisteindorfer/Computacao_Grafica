#ifndef RAYCasting_HPP
#define RAYCasting_HPP

#include "Cenário.hpp"
#include "Camera.hpp"
#include "Canvas.hpp"

class RayCasting{
    public:
    static vector<vector<vector<double>>> Ray_Casting(Cenário, Ponto, Canvas, Luz_Ambiente);
};

#endif

