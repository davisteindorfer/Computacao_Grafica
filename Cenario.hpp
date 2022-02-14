#ifndef _CENARIO_HPP
#define _CENARIO_HPP
#include "Objeto.hpp"
#include "Esfera.hpp"
#include "Cubo.hpp"
#include "Cone.hpp"
#include "Cilindro.hpp"
#include "Luz.hpp"
#include "Luz_Ambiente.hpp"
#include "Luz_Pontual.hpp"
#include "Luz_Spot.hpp"
#include "operacoes.hpp"
#include "Transformacoes.hpp"
#include "Vector.hpp"
#include <vector>
class Cenario{
    public:
    vector<Ponto> lista_pontos;
    std::vector<Objeto> lista_de_objetos();
    std::vector<Luz> lista_de_luzes();

};

#endif