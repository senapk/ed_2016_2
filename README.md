# Diário de Classe da Disciplina de ED - 2016.2

### S01E01 - Algoritmo da Princesa
### S02E01 - Queimando arvores no terminal
### S02E02 - Queimando árvores no SFML
### S03E01 - Queimando árvores aleatoriamente - Recursão
- Aplicação de Teste
### S03E02 - Algoritmo do labirinto com recursão
### S04E01 - Implementando Pilha Estática em C++
### S04E02 - Criação do labirinto com Pilha
### S05E01 - Implementação de Pilha dinâmica
**Trabalho**

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

### S05E02 - Pathfinding
- Passando trabalho de filas. Implemente a busca do pathfinding utilizando o algorimo de "floodfill".
- Na pasta do dia haverá um pdf sobre filas com o floodfill.

- Após achar o caminho entre o ponto de origem e o destino, pinte o caminho encontrado.

### S06E01 - Desenhando Fractais - Recursão
### S06E02 - Revisão Vetores dinâmicos - remoção
- Uso dos métodos default da classe Vector
### S07E01 - Lista encadeada I
- Inicio da matéria de lista encadeada.
### S07E02 - Prova teórica
### S08E01 - Prova prática
- A prova está em [LINK](./prova/prova_1.md)
- Resolução da Prova em sala

### S08E02 - Lista encadeada II
**Classe**

- Continuação de lista encadeada.
- Lista simples sem cabeça.
- Construção de iterador para lista limples.
- Adaptação do iterador para lista circular.

**Casa**
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

### S09E01 - Trabalho de listas em sala

## S10E01 - Serialização e recursão com retorno e com elo

