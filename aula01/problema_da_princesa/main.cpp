#include <iostream>
#include <list>

using namespace std;
void mostrar(list<int> lista){
    cout << "[ ";
    for(auto elemento : lista)
        cout << elemento << " ";
    cout << "]" << endl;
}

int main()
{
    int qtd = 0, esc = 0;
    //scanf ("%d %d", &qtd, &esc);
    cout << "Digite quantidade e o numero do escolhido\n";
    cin >> qtd >> esc;
    if(esc > qtd){
        cout << "Valores invalidos" << endl;
        return 1;
    }

    list<int> lista;
    for(int i = 0; i < qtd; i++){
        lista.push_back(i + 1);
    }

    cout << "Rodando elementos" << endl;
    while(lista.front() != esc){
        lista.push_back(lista.front());
        lista.pop_front();
    }
    mostrar(lista);
    while(lista.size() != 1){
        lista.push_back(lista.front());
        lista.pop_front();
        lista.pop_front();
        mostrar(lista);
    }


    return 0;
}





























