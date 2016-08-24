#include "libs/view.h"

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

void queimar(matchar &mat, Par par){
    if(par.l < 0 or par.l >= mat.sizeL())
        return;
    if(par.c < 0 or par.c >= mat.sizeC())
        return;
    my_view->paint(mat, par, 'b');
    if(mat.get(par) == 'g'){
        mat.get(par) = 'r';
        my_view->paint(mat);
        for(auto x : pegar_vizinhos(par))
            queimar(mat, x);
    }
}

int main(){
    //ALUNO
    matchar mat(20, 40, 'g');
    my_view->paint_brush(mat, "wg");
    Par p = my_view->select_point(mat, "Escolha onde comeca o fogo.");
    queimar(mat, p);
    my_view->paint(mat);
    my_view->wait();

    return 0;
}


