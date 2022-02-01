#include "operações.hpp";


double operações::ProdutoEscalar(Vector v1, Vector v2){
    return v1.get_x() * v2.get_x() + v1.get_x() * v2.get_x() + v1.get_z() * v2.get_z();
}