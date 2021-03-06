/*
 * Implemente o pathfinding com fila.
 * Encontre o menor caminho entre dois elementos
 *
 */

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
const char SPAN = '_';
const char CAMINHO = '.';

void mostrar(char mat[LIN][COL]){
    for(int l = 0; l < LIN; l++){
        for(int c = 0; c < COL; c++){
            cout << mat[l][c];
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

bool eh_furavel(char mat[LIN][COL], int l, int c){
    eh furavel se eh parede e tem no maximo um vizinho não parede
}


int criar_lab(char mat[LIN][COL], int l, int c){
    se for furavel fure
    embaralhe os vizinho
    std::random_shuffle(vet.begin(), vet.end());//para embaralhar um vetor
    chame criar lab para todos os vizinhos
}


int main(){
    srand(time(NULL));
    char mat[LIN][COL];
    for(int l = 0; l < LIN; l++){
        for(int c = 0; c < COL; c++){
            mat[l][c] = PAREDE;
        }
    }

    criar_lab(mat, 1, 1);
    mostrar(mat);

    return 0;
}
