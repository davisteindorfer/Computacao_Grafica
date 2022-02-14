#include "Cubo.hpp";
#include "operações.hpp";
#include <tuple>
Cubo::Cubo(vector<Ponto> lista_pontos, vector<Aresta> lista_arestas, vector<Face> lista_faces,Material m, int id){
    this->Lista_De_Pontos = lista_pontos;
    this->Lista_De_Aresta = lista_arestas;
    this->Lista_De_Faces = lista_faces;
    this->material = m;
    this->id = id;
};

tuple<Ponto*,Objeto*> Cubo::intercessãoReta(Raio r){
    vector< pair<Ponto*, Face> > intFace;
    for(int i = 0; i < Lista_De_Faces.size(); i++){
        Vector vetor1 = Vector(Lista_De_Faces[i].get_p1p2().get_a(),Lista_De_Faces[i].get_p1p2().get_b());
        Vector vetor2 = Vector(Lista_De_Faces[i].get_p2p3().get_a(),Lista_De_Faces[i].get_p2p3().get_b());
        normal = operações::ProdutoVetorial(vetor1, vetor2);
        Plano p = Plano(Lista_De_Faces[i].get_p1p2().get_a(), normal);
        Ponto* ponto = p.IntersecaoRaioPlano(r);


        if (ponto) {
            Vector p1p = Vector(Lista_De_Faces[i].get_p1p2().get_a(), *ponto);
            Vector p2p = Vector(Lista_De_Faces[i].get_p1p2().get_b(), *ponto);
            Vector p3p = Vector(Lista_De_Faces[i].get_p1p3().get_b(), *ponto);

            if (Lista_De_Faces[i].ValidacaoPontoFace(p1p,p2p,p3p)) {
                intFace.emplace_back(make_pair(ponto, Lista_De_Faces[i]));
                normal = p.normal;

            } else {
                p1p = Vector(Lista_De_Faces[i + 1].get_p1p2().get_a(), *ponto);
                p2p = Vector(Lista_De_Faces[i + 1].get_p1p2().get_b(), *ponto);
                p3p = Vector(Lista_De_Faces[i + 1].get_p1p3().get_b(), *ponto);

                if (Lista_De_Faces[i + 1].ValidacaoPontoFace(p1p,p2p,p3p)) {

                    intFace.emplace_back(make_pair(ponto, &Lista_De_Faces[i + 1]));

                    Vector vetor11 = Vector(Lista_De_Faces[i + 1].get_p1p2().get_a(),Lista_De_Faces[i + 1].get_p1p2().get_b());

                    Vector vetor22 = Vector(Lista_De_Faces[i + 1].get_p2p3().get_a(),Lista_De_Faces[i + 1].get_p2p3().get_b());

                    normal = operações::ProdutoVetorial(vetor11, vetor22);
                } else {
                    delete ponto;
                }
            }
        }
        if(intFace.size() == 2){
            break;
        }
        
    }
    if(!intFace.empty()) {
        if (intFace.size() >= 2) {
            if (operações::distanciaEntrePontos(r.get_origin(), intFace[0].first) <
                operações::distanciaEntrePontos(r.get_origin(), intFace[1].first)) {
                Vector vetor11 = Vector(intFace[0].second.get_p1p2().get_a(),intFace[0].second.get_p1p2().get_b());

                Vector vetor22 = Vector(intFace[0].second.get_p2p3().get_a(),intFace[0].second.get_p2p3().get_b());
               
                normal = operações::ProdutoVetorial(vetor11, vetor22);
            }
            else {
                Vector vetor11 = Vector(intFace[1].second.get_p1p2().get_a(),intFace[1].second.get_p1p2().get_b());

                Vector vetor22 = Vector(intFace[1].second.get_p2p3().get_a(),intFace[1].second.get_p2p3().get_b());
               
                normal = operações::ProdutoVetorial(vetor11, vetor22);
            }
        }
        else {
                Vector vetor11 = Vector(intFace[0].second.get_p1p2().get_a(),intFace[0].second.get_p1p2().get_b());

                Vector vetor22 = Vector(intFace[0].second.get_p2p3().get_a(),intFace[0].second.get_p2p3().get_b());
               
                normal = operações::ProdutoVetorial(vetor11, vetor22);
        }
    }
    if(intFace.empty()) {
        return make_tuple(nullptr, this);
    }
    else if(intFace.size() == 1) {
        return make_tuple(intFace[0].first, this);
    }
    else {
        if(operações::distanciaEntrePontos(intFace[0].first, r.get_origin()) < operações::distanciaEntrePontos(intFace[1].first, r.get_origin())) {
            return make_tuple(intFace[0].first, this);
        }
        else {
            return make_tuple(intFace[1].first, this);
        }
    }

}
Vector Cubo::calcularNormal(Ponto* pi){
    return normal;
}
