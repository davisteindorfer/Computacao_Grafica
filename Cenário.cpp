#include "Cenário.hpp"
#include "Transformações.hpp"

std::vector<Objeto> Cenário::lista_de_objetos(){

    // Chão
    Ponto ponto_1_chão = Ponto(0,0,-100);
    Ponto ponto_2_chão = Ponto(200,0,-100);
    Ponto ponto_3_chão = Ponto(200,0,100);
    Ponto ponto_4_chão = Ponto(0,0,100);

    vector<Ponto> lista_pontos_chao;

    lista_pontos_chao.emplace_back(ponto_1_chão);
    lista_pontos_chao.emplace_back(ponto_2_chão);
    lista_pontos_chao.emplace_back(ponto_3_chão);
    lista_pontos_chao.emplace_back(ponto_4_chão);
    
    lista_pontos.emplace_back(ponto_1_chão);
    lista_pontos.emplace_back(ponto_2_chão);
    lista_pontos.emplace_back(ponto_3_chão);
    lista_pontos.emplace_back(ponto_4_chão);

    Aresta aresta_1_chão = Aresta(ponto_1_chão,ponto_2_chão);
    Aresta aresta_2_chão = Aresta(ponto_2_chão,ponto_3_chão);
    Aresta aresta_3_chão = Aresta(ponto_3_chão,ponto_4_chão);
    Aresta aresta_4_chão = Aresta(ponto_4_chão,ponto_1_chão);
    Aresta aresta_5_chão = Aresta(ponto_1_chão,ponto_3_chão);

    vector<Aresta> lista_arestas_chao;

    lista_arestas_chao.emplace_back(aresta_1_chão);
    lista_arestas_chao.emplace_back(aresta_2_chão);
    lista_arestas_chao.emplace_back(aresta_3_chão);
    lista_arestas_chao.emplace_back(aresta_4_chão);
    lista_arestas_chao.emplace_back(aresta_5_chão);
    
    Face face_1_chão = Face(aresta_1_chão,aresta_2_chão,aresta_5_chão);
    Face face_2_chão = Face(aresta_3_chão,aresta_4_chão,aresta_5_chão);

    vector<Face> lista_faces_chao;

    lista_faces_chao.emplace_back(face_1_chão);
    lista_faces_chao.emplace_back(face_2_chão);

    //Material Pearl
    vector<double> ka_pearl = {0.0215, 0.1745, 0.0215};
    vector<double> kd_pearl = {0.07568, 0.61424, 0.07568};
    vector<double> ks_pearl = {0.633, 0.727811, 0.633};
    double m_pearl = 76.8;
    Material material_pearl = Material(ka_pearl,kd_pearl,ks_pearl, m_pearl);

    Cubo Chao = Cubo(lista_pontos_chao,lista_arestas_chao,lista_faces_chao,material_pearl, 1);

    // parede

    Ponto ponto_1_parede = ponto_1_chão;
    Ponto ponto_2_parede = ponto_2_chão;
    Ponto ponto_3_parede = Ponto(200,200,-100);
    Ponto ponto_4_parede = Ponto(0,200,-100);

    vector<Ponto> lista_pontos_parede;

    lista_pontos_parede.emplace_back(ponto_1_parede);
    lista_pontos_parede.emplace_back(ponto_2_parede);
    lista_pontos_parede.emplace_back(ponto_3_parede);
    lista_pontos_parede.emplace_back(ponto_4_parede);

    Aresta aresta_1_parede = Aresta(ponto_1_parede,ponto_2_parede);
    Aresta aresta_2_parede = Aresta(ponto_2_parede,ponto_3_parede);
    Aresta aresta_3_parede = Aresta(ponto_3_parede,ponto_4_parede);
    Aresta aresta_4_parede = Aresta(ponto_4_parede,ponto_1_parede);
    Aresta aresta_5_parede = Aresta(ponto_1_parede,ponto_3_parede);

    vector<Aresta> lista_arestas_parede;

    lista_arestas_parede.emplace_back(aresta_1_parede);
    lista_arestas_parede.emplace_back(aresta_2_parede);
    lista_arestas_parede.emplace_back(aresta_3_parede);
    lista_arestas_parede.emplace_back(aresta_4_parede);
    lista_arestas_parede.emplace_back(aresta_5_parede);

    Face face_1_parede = Face(aresta_1_parede,aresta_2_parede,aresta_5_parede);
    Face face_2_parede = Face(aresta_3_parede,aresta_4_parede,aresta_5_parede);

    vector<Face> lista_faces_parede;

    lista_faces_parede.emplace_back(face_1_parede);
    lista_faces_parede.emplace_back(face_2_parede);



}