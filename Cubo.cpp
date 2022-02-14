#include "Cubo.hpp"
#include "operacoes.hpp"

Cubo::Cubo(vector<Ponto> lista_pontos, vector<Aresta> lista_arestas, vector<Face> lista_faces,Material m, int id){
    this->Lista_De_Pontos = lista_pontos;
    this->Lista_De_Aresta = lista_arestas;
    this->Lista_De_Faces = lista_faces;
    this->material = m;
    this->id = id;
};

tuple<Ponto*,Objeto*> Cubo::IntersecaoReta(Raio r){
    vector<Ponto*> intPonto;
    vector<Face> intface;
    for(int i = 0; i < Lista_De_Faces.size(); i++){
        Vector vetor1 = Vector(Lista_De_Faces[i].get_p1p2().get_a(),Lista_De_Faces[i].get_p1p2().get_b());
        Vector vetor2 = Vector(Lista_De_Faces[i].get_p2p3().get_a(),Lista_De_Faces[i].get_p2p3().get_b());
        normal = operacoes::ProdutoVetorial(vetor1, vetor2);
        Plano p = Plano(Lista_De_Faces[i].get_p1p2().get_a(), normal);
        Ponto* ponto = p.IntersecaoRaioPlano(r);


        if (ponto) {
            Vector p1p = Vector(Lista_De_Faces[i].get_p1p2().get_a(), *ponto);
            Vector p2p = Vector(Lista_De_Faces[i].get_p1p2().get_b(), *ponto);
            Vector p3p = Vector(Lista_De_Faces[i].get_p1p3().get_b(), *ponto);

            if (Lista_De_Faces[i].ValidacaoPontoFace(p1p,p2p,p3p)) {

                intPonto.push_back(ponto);
                intface.push_back(Lista_De_Faces[i]);
                normal = p.normal;

            } else {
                p1p = Vector(Lista_De_Faces[i + 1].get_p1p2().get_a(), *ponto);
                p2p = Vector(Lista_De_Faces[i + 1].get_p1p2().get_b(), *ponto);
                p3p = Vector(Lista_De_Faces[i + 1].get_p1p3().get_b(), *ponto);

                if (Lista_De_Faces[i + 1].ValidacaoPontoFace(p1p,p2p,p3p)) {
                    intPonto.push_back(ponto);
                    intface.push_back(Lista_De_Faces[i + 1]);

                    Vector vetor11 = Vector(Lista_De_Faces[i + 1].get_p1p2().get_a(),Lista_De_Faces[i + 1].get_p1p2().get_b());

                    Vector vetor22 = Vector(Lista_De_Faces[i + 1].get_p2p3().get_a(),Lista_De_Faces[i + 1].get_p2p3().get_b());

                    normal = operacoes::ProdutoVetorial(vetor11, vetor22);
                } else {
                    delete ponto;
                }
            }
        }
        if(intface.size() == 2){
            break;
        }
        
    }
    if(!intface.empty()) {
        if (intface.size() >= 2) {
            if (operacoes::distanciaEntrePontos(r.get_origin(), intPonto[0]) <
                operacoes::distanciaEntrePontos(r.get_origin(), intPonto[1])) {
                Vector vetor11 = Vector(intface[0].get_p1p2().get_a(),intface[0].get_p1p2().get_b());

                Vector vetor22 = Vector(intface[0].get_p2p3().get_a(),intface[0].get_p2p3().get_b());
               
                normal = operacoes::ProdutoVetorial(vetor11, vetor22);
            }
            else {
                Vector vetor11 = Vector(intface[1].get_p1p2().get_a(),intface[1].get_p1p2().get_b());

                Vector vetor22 = Vector(intface[1].get_p2p3().get_a(),intface[1].get_p2p3().get_b());
               
                normal = operacoes::ProdutoVetorial(vetor11, vetor22);
            }
        }
        else {
                Vector vetor11 = Vector(intface[0].get_p1p2().get_a(),intface[0].get_p1p2().get_b());

                Vector vetor22 = Vector(intface[0].get_p2p3().get_a(),intface[0].get_p2p3().get_b());
               
                normal = operacoes::ProdutoVetorial(vetor11, vetor22);
        }
    }
    if(intface.empty()) {
        return make_tuple(nullptr, this);
    }
    else if(intface.size() == 1) {
        return make_tuple(intPonto[0], this);
    }
    else {
        if(operacoes::distanciaEntrePontos(intPonto[0], r.get_origin()) < operacoes::distanciaEntrePontos(intPonto[1], r.get_origin())) {
            return make_tuple(intPonto[0], this);
        }
        else {
            return make_tuple(intPonto[1], this);
        }
    }

}
Vector Cubo::calcularNormal(Ponto* pi){
    return normal;
}
