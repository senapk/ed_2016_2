
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../libs/sortview.h"
#include "../libs/player.h"

static SortView sview;

void minimum_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam; i++, tam--){
        int menor = i;
        int maior = i;
        for(int j = i; j < tam; j++){
            if(vet[j] > vet[maior])
                maior = j;
            if(vet[j] < vet[menor])
                menor = j;
            sview.show(vet, {i, tam - 1, j, menor, maior}, "rrygb");
        }
        if((maior == i) && (menor == tam - 1))
            std::swap(vet[maior], vet[menor]);
        else{
            std::swap(vet[i], vet[menor]);
            if(maior == i)
                maior = menor;
            std::swap(vet[tam - 1], vet[maior]);
        }
        sview.show(vet, {i, tam - 1, menor, maior}, "rrgb");
    }
}

void bubble_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = tam - 1; i >= 0; i--)
        for(int j = 0; j < i; j++)
            if(vet[j] > vet[j + 1])
                std::swap(vet[j], vet[j + 1]);
    sview.show(vet);
}

std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

#include <algorithm>
//[inicio fim[
void mergesort(std::vector<int> &vet, int inicio, int fim){
    if(fim == inicio + 1)
        return;

    int meio = (fim + inicio) / 2;

    mergesort(vet, inicio, meio);
    mergesort(vet, meio, fim);

    std::inplace_merge(vet.begin() + inicio,
                       vet.begin() + meio,
                       vet.begin() + fim);
    sview.show(vet);
}

int main_sorts(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);

    mergesort(vet, 0, vet.size());

    my_player->wait();
    return 0;
}


int main(){
    main_sorts();
}

