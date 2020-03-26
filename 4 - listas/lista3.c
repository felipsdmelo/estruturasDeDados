#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//inserindo na lista sem ordenacao, sempre na última posição
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
    Celula *p, *pR;
	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
    novo->prox = NULL;
    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //numero inserido como primeiro
    if (!pR) {
        novo->prox = p; //ou novo->prox = lista;
        return novo;
    } else if (p == NULL) {//numero inserido na ultima posicao
        pR->prox = novo;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->prox = p;
    }	
	return lista; //retornamos o primeiro elemento
}

void exibir(Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }
    for (p = lista; p; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("\n");
}

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    for (p = lista; p; p = p->prox, total++);

    return total;
}

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    for (i = 0; i < quantidade; i++ ) {
        lista = inserir(rand() % 100, lista);
    }

    return lista;
}

Celula *excluir(int valor, Celula *lista) {
    Celula *p, *pR, *lixo;

    if (!lista) {
        return lista; //return NULL;
    }

    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->conteudo) {
            printf("Valor localizado e será removido\n");
            break;
        }
    }

    if (!p) {
        printf("Valor não localizado\n");
        return lista;
    }
    //valor é o primeiro elemento
    if (!pR) { // if (p == lista)
        //código para remover o primeiro elemento
        lista = lista->prox;
    } else if (!p->prox) {
        //código para remover o último elemento
        pR->prox = NULL;
    } else {
        //código para remover o elemento que estiver no meio da lista
        pR->prox = p->prox;
    }
    free(p);
    return lista;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;
    
    lista = popular(lista,5);
    exibir(lista);

    int numero;
    printf("Digite um número da lista para excluir: ");
    scanf("%d", &numero);
    lista = excluir(numero, lista);

    printf("Números na lista após exclusão\n");
    exibir(lista);

	return 1;
}







