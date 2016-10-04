#include <iostream>
#include <list>
#include <vector>
#include <ctime>//srand(time(NULL))
#include <cstdlib>//rand
#include <algorithm>

using namespace std;

const int LIN = 20;
const int COL = 60;

const char PAREDE = '#';
const char VAZIO = ' ';

void mostrar(char mat[LIN][COL]){
    for(int l = 0; l < LIN; l++){
        for(int c = 0; c < COL; c++){
            if(mat[l][c] == PAREDE)
                std::cout << "\u2588";
            else
                std::cout << VAZIO;
        }
        cout << endl;
    }
}

struct Par{
    int l, c;
};

vector<Par> pegar_vizinhos(int l, int c){
    vector<Par> adj;

    adj.push_back(Par{l, c - 1});
    adj.push_back(Par{l, c + 1});
    adj.push_back(Par{l - 1, c});
    adj.push_back(Par{l + 1, c});
    return adj;
}

bool eh_igual(char mat[LIN][COL], int l, int c, char value){
    if(l < 0 || l >= LIN)
        return false;
    if(c < 0 || c >= COL)
        return false;
    return (mat[l][c] == value);
}

bool eh_furavel(char mat[LIN][COL], int l, int c){
    if(eh_igual(mat, l, c, PAREDE)){
        int cont = 0;
        auto vizinhos = pegar_vizinhos(l, c);
        for(auto viz : vizinhos){
            if(!eh_igual(mat, viz.l, viz.c, PAREDE))
                cont++;
        }
        return (cont <= 1);
    }
    return false;
}


int criar_lab(char mat[LIN][COL], int l, int c){
    int cont = 0;
    if(eh_furavel(mat, l, c)){
        cont++;
        mat[l][c] = VAZIO;
        auto vizinhos = pegar_vizinhos(l, c);
        std::random_shuffle(vizinhos.begin(), vizinhos.end());
        for(auto viz : vizinhos){
            cont += criar_lab(mat, viz.l, viz.c);
        }
    }
    return cont;
}


int main(){
    srand(time(NULL));
    char mat[LIN][COL];
    for(int l = 0; l < LIN; l++){
        for(int c = 0; c < COL; c++){
            mat[l][c] = PAREDE;
        }
    }

    int cont = criar_lab(mat, 1, 1);
    mostrar(mat);
    cout << "Furei " << cont << " paredes" << endl;

    return 0;
}




























