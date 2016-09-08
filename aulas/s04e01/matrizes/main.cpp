#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char VAZIO = 'w';

//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

vector<Par> vizinhos(Par par){
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

bool eh_furavel(matchar &mat, Par p){
    int cont = 0;
    if(!mat.equals(p, PAREDE))
        return false;
    for(auto &viz : vizinhos(p)){
        if(mat.equals(viz, PAREDE))
            cont++;
    }
    return (cont >= 3);
}

int sortear(int x){
    return rand() % x;
}

void mostrar_lab(matchar &mat, stack<Par> pilha){
    mat_draw(mat);
    while (!pilha.empty()){
        mat_focus(pilha.top(), 'y');
        pilha.pop();
    }
    ed_show();
}

void criar_lab(matchar &mat, stack<Par> &pilha){
    mat.get(Par(1, 1)) = VAZIO;
    pilha.push(Par(1, 1));

    while(!pilha.empty()){
        vector<Par> furaveis;
        for(auto viz : vizinhos(pilha.top()))
            if(eh_furavel(mat, viz))
                furaveis.push_back(viz);
        if(furaveis.size() == 0){
            pilha.pop();
            mostrar_lab(mat, pilha);
        }else{
            //selecionar um dos vizinhos furaveis
            Par sortudo = furaveis[sortear(furaveis.size())];
            mat.get(sortudo) = VAZIO;
            pilha.push(sortudo);
            mostrar_lab(mat, pilha);
        }

    }
}


int main(){
    stack<Par> pilha;
    matchar mat(nlinhas, ncolunas, PAREDE);
    criar_lab(mat, pilha);
    mat_draw(mat);
    ed_show();

    ed_lock();

    return 0;
}


