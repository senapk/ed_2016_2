## S08E01
- Estudar e refazer a lista simples.
- Estudar e refazer o interator.
- Transformar a lista simples para lista recursiva.
- Fazer os seguintes métodos recursivos

```
    int pegar_casa(int num, int casa)
    int contar_casas(int num)
    int somar_digitos(int num);
    int inverter_numero(int num);
        98493 -> 39489
    int rotacionar_esquerda(int num)
        98493 -> 84939
    int rotacionar_direita(int num)
        98493 -> 39849
```

## S05E02
Passando trabalho de filas. Implemente a busca do pathfinding utilizando o algorimo de "floodfill".
Na pasta do dia haverá um pdf sobre filas com o floodfill.

Após achar o caminho entre o ponto de origem e o destino, pinte o caminho encontrado.


## S05E01
Lembre de se inscrever em qxcode.slack.com e tire suas dúvidas lá.

### Trabalho
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

    //remove o elemento da posição deslocando para trás 
    void remove(int pos);
```
