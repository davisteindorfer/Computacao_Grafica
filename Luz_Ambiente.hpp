#ifndef _LUZ_AMBIENTE_HPP
#define _LUZ_AMBIENTE_HPP
#include <vector>
using namespace std;
#include "Luz.hpp"
#include "Material.hpp"
class Luz_Ambiente : public Luz{
    public:
    Luz_Ambiente(vector<double>);
    vector<double> Intensidade_luz_ambiente(Material);
};

#endif