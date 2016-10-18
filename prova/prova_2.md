
Nome:

Você deve entregar uma única folha com os pseudocódigos das respostas.
Se não souber uma questão toda, faça o que souber.
Conte 2 horas exatas a partir do início da prova e depois entregue a prova.


1. Dado um vetor dinâmico, faça a operação de remover todos. Dado um valor, remova todas as ocorrencias desse valor no vetor.

```
struct Vetor{
    int * _data;
    int _size, _max;
};

void remover_todos(vetor, value);

Ex:
entrada:
vetor = 4 9 3 2 2 9 2
value = 2
saida esperada = 4 9 3 9
```

---

2. Faça o pseudocódigo de encontrar o menor caminho com filas.

```
matriz<char> mat;
matriz<int> dist;

Par inicio;
Par fim;
```

Retorne o caminho que liga os dois pontos, se o caminho existir.
List<Par> encontrar_caminho(mat, inicio, fim);

---
3. Faça o pseudocódigo da construção do labirinto com pilha.

```
matriz<char> mat;
use as Contantes PAREDE e VAZIO para.
```
