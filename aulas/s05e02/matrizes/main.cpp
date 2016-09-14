#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue> //fila

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

//MAPA DE CORES
//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

vector<Par> adjacentes(Par p){
    vector<Par> adj(8, p);
    adj[0].l += 1;
    adj[1].l -= 1;
    adj[2].c += 1;
    adj[3].c -= 1;
    adj[4] = p + Par(-1, -1);
    adj[5] = p + Par(-1, 1);
    adj[6] = p + Par(1, 1);
    adj[7] = p + Par(1, -1);
    return adj;
}

//se houver caminho, preencha a matriz de distancias
//e retorne true
bool buscar(matchar &mat, matriz<int> &dist,
            Par inicio, char cor, Par dest){

    queue<Par> fila;
    mat.get(inicio) = 'c';//marcar
    dist.get(inicio) = 0;
    fila.push(inicio);

    while(fila.size() != 0){
        mat.get(fila.front()) = 'r';
        for(auto elem : adjacentes(fila.front())){
            if(mat.is_inside(elem)){
                if(mat.get(elem) == cor){
                    mat.get(elem) = 'c';
                    fila.push(elem);
                    dist.get(elem) = dist.get(fila.front()) + 1;

                    mat_draw(mat);
                    mat_focus(elem, 'y');
                    mat_draw(dist);
                    ed_show();
                    if(elem == dest)
                        return true;
                }

            }
        }
        fila.pop();
    }

    //DESENHO
    return false;
}

int main(){
    //cria uma matriz de caracteres de 15 linhas por 20 colunas, e preenche todos os elementos
    //com 'y'
    matriz<char> mat(15, 20, 'g');
    matriz<int> dist(15, 20, -1);

    //chama o metodo de desenho livre onde a cor primeira default eh branca
    mat_paint_brush(mat, "wg");

    Par inicio = mat_get_click(mat, "escolha inicio");
    Par destino = mat_get_click(mat, "escolha destino");
    char cor = mat.get(inicio);
    bool achou = buscar(mat, dist, inicio, cor, destino);
    if(achou)
        mostrar_caminho(mat, dist, inicio, dest);

    ed_lock();//impede que termine abruptamente

    return 0;
}



