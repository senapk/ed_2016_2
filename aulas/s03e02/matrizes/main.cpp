#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int nlinhas = 20;
int ncolunas = 35;

//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l, par.c - 1));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l + 1, par.c));
    return vizinhos;
}

vector<Par> shuffle(vector<Par> &vet){
    for(int i = 0; i < (int) vet.size(); i++){
        std::swap(vet[i], vet[rand() % (int) vet.size()]);
    }
    return vet;
}

bool eh_caminho(matchar &mat, Par p, Par destino){
    if(p.l < 0 || p.l >= mat.sizeL())
        return false;
    if(p.c < 0 || p.c >= mat.sizeC())
        return false;
    if(p == destino){
        return true;
    }


    mat_draw(mat);
    mat_focus(p, 'y');
    ed_show();

    //se for arvore
    if(mat.get(p) == 'g'){
        //para cada um dos vizinhos de p
        mat.get(p) = 'r';//antes da recursão
        mat_draw(mat);
        ed_show();
        auto viz = pegar_vizinhos(p);
        shuffle(viz);
        for(auto par : viz){

            if(eh_caminho(mat, par, destino)){
                mat.get(p) = 'b';
                mat_draw(mat);
                ed_show();
                return true;
            }
        }

        mat.get(p) = 'k';//antes da recursão
        mat_draw(mat);
        ed_show();

        return false;

    }
    return 0;
}



int main(){
    matchar mat(nlinhas, ncolunas, 'w');
    mat_paint_brush(mat, "gw");
    Par p = mat_get_click(mat, "Escolha onde comeca o fogo.");
    Par dest = mat_get_click(mat, "Escolha o destino");
    eh_caminho(mat, p, dest);
    mat_draw(mat);

    ed_lock();

    return 0;
}


