#include <iostream>
#include <list>
#include <vector>
#include <ctime>//srand(time(NULL))
#include <cstdlib>//rand

using namespace std;

const int linhas = 20;
const int colunas = 60;

void mostrar(char mat[linhas][colunas]){
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            cout << mat[l][c];
        }
        cout << endl;
    }
}

void limpar(){
    for(int i = 0; i < 20; i++){
        cout << endl;
    }
}

void esperar(){
    char c;
    cin >> std::noskipws >> c;
}

struct Par{
    int l, c;
};

vector<Par> adjacentes(int l, int c){
    vector<Par> adj;

    adj.push_back(Par{l, c - 1});
    adj.push_back(Par{l, c + 1});
    adj.push_back(Par{l - 1, c});
    adj.push_back(Par{l + 1, c});
    return adj;
}

int queimar(int l, int c, char mat[linhas][colunas]){
    int cont = 0;
    if(l < 0 or l >= linhas)
        return 0;
    if(c < 0 or c >= colunas)
        return 0;
    if(mat[l][c] == '#'){
        cont = 1;
        mat[l][c] = '_';
        limpar();
        mostrar(mat);
        esperar();
        for(auto par : adjacentes(l, c)){
            cont += queimar(par.l, par.c, mat);
        }
    }
    return cont;
}



int main(){
    srand(time(NULL));
    char mat[linhas][colunas];
    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            mat[l][c] = '.';
        }
    }

    int qtd = 700;
    for(int i = 0; i < qtd; i++){
        mat[rand() % linhas][rand() % colunas] = '#';
    }

    limpar();
    mostrar(mat);

    cout << "Digite linha e coluna para fogo" << endl;
    int lin, col;
    cin >> lin >> col;

    int cont = queimar(lin, col, mat);
    cout << "Arvores queimadas." << cont << endl;

    return 0;
}































