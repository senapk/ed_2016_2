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

template <class T>
void shuffle(vector<T> &vet){
    for(int i = 0; i < (int) vet.size(); i++){
        std::swap(vet[i], vet[rand() % (int) vet.size()]);
    }
}

void queimar(matchar &mat, Par par){
    if(par.l < 0 or par.l >= mat.sizeL())
        return;
    if(par.c < 0 or par.c >= mat.sizeC())
        return;
    mat_draw(mat);
    mat_focus(par, 'y');
    ed_show();

    if(mat.get(par) == 'g'){
        mat.get(par) = 'r';
        mat_draw(mat);
        ed_show();

        auto viz = pegar_vizinhos(par);
        shuffle(viz);
        for(auto x : viz)
            queimar(mat, x);
    }
}

int main(){
    matchar mat(nlinhas, ncolunas, 'g');
    mat_paint_brush(mat, "wg");
    Par p = mat_get_click(mat, "Escolha onde comeca o fogo.");
    queimar(mat, p);
    mat_draw(mat);

    ed_lock();

    return 0;
}


