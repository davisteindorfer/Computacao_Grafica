#include "Cenario.hpp"
#include "Transformacoes.hpp"

std::vector<Objeto*> Cenario::lista_de_objetos(){
    vector<Objeto*> Lista_objetos;
    // Chao
    Ponto ponto_1_chao = Ponto(0,0,-10);
    Ponto ponto_2_chao = Ponto(20,0,-10);
    Ponto ponto_3_chao = Ponto(20,0,10);
    Ponto ponto_4_chao = Ponto(0,0,10);

    vector<Ponto> lista_pontos_chao;

    lista_pontos_chao.emplace_back(ponto_1_chao);
    lista_pontos_chao.emplace_back(ponto_2_chao);
    lista_pontos_chao.emplace_back(ponto_3_chao);
    lista_pontos_chao.emplace_back(ponto_4_chao);
    
    lista_pontos.emplace_back(ponto_1_chao);
    lista_pontos.emplace_back(ponto_2_chao);
    lista_pontos.emplace_back(ponto_3_chao);
    lista_pontos.emplace_back(ponto_4_chao);

    Aresta aresta_1_chao = Aresta(ponto_1_chao,ponto_2_chao);
    Aresta aresta_2_chao = Aresta(ponto_2_chao,ponto_3_chao);
    Aresta aresta_3_chao = Aresta(ponto_3_chao,ponto_4_chao);
    Aresta aresta_4_chao = Aresta(ponto_4_chao,ponto_1_chao);
    Aresta aresta_5_chao = Aresta(ponto_1_chao,ponto_3_chao);

    vector<Aresta> lista_arestas_chao;

    lista_arestas_chao.emplace_back(aresta_1_chao);
    lista_arestas_chao.emplace_back(aresta_2_chao);
    lista_arestas_chao.emplace_back(aresta_3_chao);
    lista_arestas_chao.emplace_back(aresta_4_chao);
    lista_arestas_chao.emplace_back(aresta_5_chao);
    
    Face face_1_chao = Face(aresta_1_chao,aresta_2_chao,aresta_5_chao);
    Face face_2_chao = Face(aresta_3_chao,aresta_4_chao,aresta_5_chao);

    vector<Face> lista_faces_chao;

    lista_faces_chao.emplace_back(face_1_chao);
    lista_faces_chao.emplace_back(face_2_chao);

    //Material Pearl
    vector<double> ka_pearl = {0.0215, 0.1745, 0.0215};
    vector<double> kd_pearl = {0.07568, 0.61424, 0.07568};
    vector<double> ks_pearl = {0.633, 0.727811, 0.633};
    double m_pearl = 76.8;
    Material material_pearl = Material(ka_pearl,kd_pearl,ks_pearl, m_pearl);

    Cubo Chao = Cubo(lista_pontos_chao,lista_arestas_chao,lista_faces_chao,material_pearl, 1);

    Lista_objetos.push_back(&Chao);
    
    // parede

    Ponto ponto_1_parede = ponto_1_chao;
    Ponto ponto_2_parede = ponto_2_chao;
    Ponto ponto_3_parede = Ponto(200,200,-100);
    Ponto ponto_4_parede = Ponto(0,200,-100);

    vector<Ponto> lista_pontos_parede;

    lista_pontos_parede.emplace_back(ponto_1_parede);
    lista_pontos_parede.emplace_back(ponto_2_parede);
    lista_pontos_parede.emplace_back(ponto_3_parede);
    lista_pontos_parede.emplace_back(ponto_4_parede);

    lista_pontos.emplace_back(ponto_1_parede);
    lista_pontos.emplace_back(ponto_2_parede);
    lista_pontos.emplace_back(ponto_3_parede);
    lista_pontos.emplace_back(ponto_4_parede);

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

    Cubo Parede = Cubo(lista_pontos_parede,lista_arestas_parede,lista_faces_parede,material_pearl, 2);
    Lista_objetos.push_back(&Parede);

    return Lista_objetos;
}

std::vector<Luz*> Cenario::lista_de_luzes(){
    vector<Luz*> lista_luzes;
    vector<double> ia = {0,0,0};
    vector<double> id = {0.3,0.3,0.3};
    vector<double> is = {0.4,0.4,0.4};
    Ponto p = Ponto(20,10,10);
    Luz_Pontual l = Luz_Pontual(ia,id,is,p);
    lista_luzes.push_back(&l);
    lista_pontos.push_back(p);
    return lista_luzes;
}