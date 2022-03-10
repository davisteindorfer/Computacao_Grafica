#include "RayCasting.hpp"
#include "Cenario.hpp"
#include "Canvas.hpp"
#include "Camera.hpp"
#include "operacoes.hpp"
#include <GL/glut.h>
#include "renderizacao.hpp"



int main(int argc, char* argv[]){
    Cenario cena = Cenario();
    vector<Objeto*> lista_obj = cena.lista_de_objetos();
    vector<Luz*> lista_luz = cena.lista_de_luzes();
    Vector eye = Vector(20,10,20);
    Vector lookat = Vector(-20,10,20);
    Vector viewup = Vector(20,11,20);
    Camera camera = Camera(eye,lookat,viewup);
    for(int i = 0; i < lista_obj.size();i++){
        cena.lista_pontos[i] = camera.Mundo_camera(cena.lista_pontos[i]);
    }
    Canvas frame = Canvas(800,800,1,1,100,800,800);

    vector<double> aux_luz_ambiente = {0.5,0.5,0,5};
    Luz_Ambiente luzAmbiente = Luz_Ambiente(aux_luz_ambiente);
    vector<vector<vector<double>>> matriz_cores = RayCasting::Ray_Casting(cena, Ponto(0,0,0), frame, luzAmbiente);
    renderizar(&frame, matriz_cores);


}