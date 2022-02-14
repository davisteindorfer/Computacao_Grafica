#include "RayCasting.hpp"
#include "Cenario.hpp"
#include "Objeto.hpp"
#include <tuple>

RayCasting::RayCasting(){}

vector<vector<vector<double>>> RayCasting::Ray_Casting(Cenario cena, Ponto posicao_olho, Canvas frame, Luz_Ambiente Luz_Ambiente){

    vector<double> intensidadePixel;
    bool auxDefinido = false;

    Objeto* objeto_interceptado;

    Ponto* p_intercecao;

    Ponto P00 = Ponto(-(frame.largura/2)+(frame.deltaX/2), (frame.altura/2)-(frame.deltaY/2), frame.d);

    std::vector<std::vector<vector<double>>> matriz_de_cores;
    vector<Objeto*> listobj = cena.lista_de_objetos();
    vector<Luz*> listluz = cena.lista_de_luzes();
    //percorrendo linhas do canvas
    
    for(int i = 0; i< frame.num_linhas; i++){

        double py = P00.y - (i*frame.deltaY);

        //percorrendo colunas do canvas

        for(int j = 0; j< frame.num_colunas; i++){
            double px = P00.x + (j*frame.deltaX);
            Vector ponto_canvas = Vector(px,py,frame.d);
            Raio r = Raio(posicao_olho, ponto_canvas);

            //percorrendo objetos do cenario para checar se há interecessao com o raio

            for(int t = 0; t < listobj.size(); t++){
                tuple<Ponto*,Objeto*> aux2;
                if(listobj[t]->name == "Cubo"){
                    Cubo Oi = Cubo(listobj[t]->Lista_De_Pontos,listobj[t]->Lista_De_Aresta,listobj[t]->Lista_De_Faces, listobj[t]->material, listobj[t]->id);
                    aux2 = Oi.IntersecaoReta(r);
                    if(get<0>(aux2)){
                    double distancia_orig = 10000000;
                    Vector inte = Vector(get<0>(aux2)->x, get<0>(aux2)->y, get<0>(aux2)->z);
                    if(sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte) < distancia_orig)){
                        distancia_orig = sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte));
                        objeto_interceptado = get<1>(aux2);
                        auxDefinido = true;
                        
                        p_intercecao = new Ponto(inte.x,inte.y,inte.z);
                    }
                }
                }
                if(listobj[t]->name == "Esfera"){
                    Esfera Oi = Esfera(listobj[t]->raio,listobj[t]->centro1,listobj[t]->material, listobj[t]->id);
                    aux2 = Oi.IntersecaoReta(r);
                    if(get<0>(aux2)){
                    double distancia_orig = 10000000;
                    Vector inte = Vector(get<0>(aux2)->x, get<0>(aux2)->y, get<0>(aux2)->z);
                    if(sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte) < distancia_orig)){
                        distancia_orig = sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte));
                        objeto_interceptado = get<1>(aux2);
                        auxDefinido = true;
                        p_intercecao = new Ponto(inte.x,inte.y,inte.z);
                    }
                }
                }
                if(listobj[t]->name == "Cone"){
                    Cone Oi = Cone(listobj[t]->altura, listobj[t]->raio, listobj[t]->centro, listobj[t]->normal,listobj[t]->material, listobj[t]->id);
                    aux2 = Oi.IntersecaoReta(r);
                    if(get<0>(aux2)){
                    double distancia_orig = 10000000;
                    Vector inte = Vector(get<0>(aux2)->x, get<0>(aux2)->y, get<0>(aux2)->z);
                    if(sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte) < distancia_orig)){
                        distancia_orig = sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte));
                        objeto_interceptado = get<1>(aux2);
                        auxDefinido = true;
                        p_intercecao = new Ponto(inte.x,inte.y,inte.z);
                    }
                }
                }
                if(listobj[t]->name == "Cilindro"){
                    Cilindro Oi = Cilindro(listobj[t]->altura, listobj[t]->raio, listobj[t]->centro, listobj[t]->normal, listobj[t]->material, listobj[t]->id);
                    aux2 = Oi.IntersecaoReta(r);
                    if(get<0>(aux2)){
                    double distancia_orig = 10000000;
                    Vector inte = Vector(get<0>(aux2)->x, get<0>(aux2)->y, get<0>(aux2)->z);
                    if(sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte) < distancia_orig)){
                        distancia_orig = sqrt(operacoes::ProdutoEscalar(Vector(0,0,0),inte));
                        objeto_interceptado = get<1>(aux2);
                        auxDefinido = true;
                        p_intercecao = new Ponto(inte.x,inte.y,inte.z);
                    }
                }
                }
            }
            if (auxDefinido){
                intensidadePixel = Luz_Ambiente.Intensidade_luz_ambiente(objeto_interceptado->material);
                for(int t= 0; t<listluz.size(); t++){
                    Luz* li = listluz[t];
                    Vector calc_int_difusa = li->calcular_Intensidade_Difusa(p_intercecao,objeto_interceptado->material,objeto_interceptado->calcularNormal(p_intercecao));
                    Vector calc_int_espec = li->calcularIntensidadeEspecular(p_intercecao,objeto_interceptado->material,objeto_interceptado->calcularNormal(p_intercecao));
                    intensidadePixel[0] = intensidadePixel[0] + calc_int_difusa.x;
                    intensidadePixel[1] = intensidadePixel[1] + calc_int_difusa.y;
                    intensidadePixel[2] = intensidadePixel[2] = calc_int_difusa.z;
                    intensidadePixel[0] = intensidadePixel[0] + calc_int_espec.x;
                    intensidadePixel[1] = intensidadePixel[1] + calc_int_espec.y;
                    intensidadePixel[2] = intensidadePixel[2] = calc_int_espec.z;
                }
                matriz_de_cores[i][j] = intensidadePixel;
            }
            
        }
    }
        return matriz_de_cores;
}