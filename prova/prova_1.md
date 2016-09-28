1. Dado um vetor dinâmico, faça a operação de push_back(). Duplique o vetor, caso, chegue ao limite.
struct Vetor{
    int * _data;
    int _size, _max;
};
funcao push_back(valor):   **.5 ponto testar duplicar**
    se tamanho == max
        dobra_tamanho
    fim
    data[size] = valor
    incrementa tamanho de 1 **.5 incremento**
fim

funcao dobrar_tamanho()
    aux = vetor           **1 ponto backup**
    max = 2 * max
    vetor = novo vetor com novo tam max
    para cada valor em aux  **1 realocacao**
        insere em vetor
    desaloca aux           **.5 para desalocar**

2. Faça o algoritmo para preenchimento de imagens com filas. Pinte de PRETO tudo que for da cor do ponto de inicio.
matriz<char> mat;
Par inicio;
void preencher(mat, inicio)
    cor inicial = mat[inicio] **.3 criar, .3 inserir**
    criar fila                **.3 marcar**
    marcar pos inicial        **1 para criterio de insercao**
    _gambi_                   **.5 para marcar e inserir**
    inserir na fila           **1 para remocao e pintura**
    while fila nao estiver vazia:
        para cada vizinho do elemento da frente:
            se existir na matriz e for da cor: 
                marca o vizinho
                insere na fila
        pinta o elemento da frente
        remove o da frente

3. Faça o algoritmo de resolução do labirinto perfeito com pilha. Retorne uma lista com os pontos entre inicio e fim se existir caminho entre eles. Use as constantes VAZIO, PAREDE
list<Par> fazer_caminho(mat, inicio, fim):
    criar pilha              **0.5 para inicializar**
    inserir inicio na pilha
    marcar mat[inicio]
    while pilha nao for vazia && topo != fim:(.5 para saida)
        pegar vizinhos furados nao marcados do topo (1 ponto)
        if vizinhos for vazio (0.5 desempilha se vazio)
            desempilha o topo
        senao
            escolhe um vizinho (0.5 escolhe e empilha)
            marca e empilha
    retorna pilha
            
            
        







