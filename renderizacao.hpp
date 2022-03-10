#ifndef RENDERIZACAO_HPP
#define RENDERIZACAO_HPP

#include "Canvas.hpp"
#include<GL/glut.h>

vector<vector<vector<double>>> matrizCores;
double deltaX, deltaY;

void configIniciais(Canvas jan) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, jan.largura, jan.altura, 0);
}

void setPixel(int x, int y) {

}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int x=0; x<matrizCores.size(); x++) {
        for(int y =0; y<matrizCores[x].size(); y++) {
            glBegin(GL_QUADS);
                glColor3f(matrizCores[x][y][1],
                          matrizCores[x][y][2],
                          matrizCores[x][y][3]);
                        //glColor3f(0,0,1);
                glVertex2i(deltaX*y , deltaY*x);
                glVertex2i((deltaX*y)+deltaX, deltaY*x);
                glVertex2i((deltaX*y)+deltaX , (deltaY*x)+deltaY);
                glVertex2i(deltaX*y , (deltaY*x)+deltaY);
            glEnd();
        }
    }
    glFlush();
}

void renderizar(Canvas *janela, vector<vector<vector<double>>> matrizCores) {
    int endereco=1;
    glutInit(&endereco, NULL);
    glutInitWindowSize(janela->largura, janela->altura);
    glutCreateWindow("Cenario");
    deltaX = janela->deltaX;
    deltaY = janela->deltaY;
    
    configIniciais(*janela);

    glutDisplayFunc(display); 
    glutMainLoop(); 
}

#endif