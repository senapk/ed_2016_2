


## S05E01

Alterar a **Pilha** para **Vector** retirando os métodos push, pop e top e inserindo os métodos.

```c++
    int &front();//retorna referencia do primeiro elemento
    int &back();//retorna referencia do ultimo elemento

    int * begin();//retorna o ponteiro para o primeiro elemento ou nullptr
    int * end();//retorna o ponteiro para um elemento após o último
    void push_back(int value);//insere no fim
    void pop_back();//retira do fim
    int &get(int indice);//retorna a referencia ao elemento desse indice

    //insere em pos deslocando para frente quem estava em pos e outros
    void insert(int value, int pos);

    //insere em pos deslocando para frente quem estava em pos e outros
    void insert(int value, int *pos);
``` 
