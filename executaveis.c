#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void inicializa_pilha ( Pilha *p, int c ){
    p->dados = malloc( sizeof(int) * c );
    p->capacidade = c;
    p->topo = -1;
}

int pilha_vazia ( Pilha p ) {
    return p.topo == -1;
}

int pilha_cheia ( Pilha p ) {
    return p.topo == p.capacidade - 1;
}

int empilha ( Pilha *p, int info ) {
    if( pilha_cheia ( *p ) )
        return ERRO_PILHA_CHEIA;

    p->topo++;
    p->dados[p->topo] = info;
    return 1; // Sucesso
}

int desempilha ( Pilha *p, int *info ) {
    if ( pilha_vazia ( *p ) )
        return ERRO_PILHA_VAZIA;

    *info = p->dados[p->topo];
    p->topo--;
    return 1; // Sucesso
}

void mostra_pilha ( Pilha p ) {
    if( pilha_vazia ( p ) )
        printf("Pilha vazia!\n");
    else{
        printf("Dados da Pilha:\n");
        int i;
        for( i=0 ; i <= p.topo ; i++)
            printf("%d\n", p.dados[i]);
   }
}

void desaloca_pilha( Pilha *p ){
    free( p->dados );
}


int **inicializa_grafo(int dimensao){

    int i, j;
    FILE *fp;
    int **grafo = (int **) malloc(dimensao * sizeof(int *));
    
    for (i = 0; i < dimensao; i++) {
        grafo[i] = (int *) malloc(dimensao * sizeof(int));
    }

    fp = fopen("texto.txt", "r");

    for (i = 0; i < dimensao; ++i)
    {
        for (j = 0; j < dimensao; ++j)
        {
            fscanf(fp, "%d", grafo[i] + j);
        }
    }

    fclose(fp);
    
    return grafo;
}

void mostra_grafo(int **grafo, int dimensao){
    printf("Dados da matriz %dx%d:\n", dimensao, dimensao);
    int i, j;
    for(i = 0 ; i < dimensao; i++){
        for( j = 0 ; j < dimensao ; j++ )
            printf("%4d ", grafo[i][j]);
        printf("\n");
    }
    printf("\n");
}

void inicializa_fila ( Fila *p ){
	p->inicio = 0;
	p->n = 0;
}

int fila_vazia ( Fila f ) {
	return f.n == 0;
}

int fila_cheia ( Fila f ) {
	return f.n == MAX;
}

int inserir ( Fila *p, int info ){
	if( fila_cheia ( *p ) )
		return ERRO_FILA_CHEIA;
	
	int fim = ( p->inicio + p->n ) % MAX;
	p->dados[fim] = info;
	p->n++;
	return 1; // Sucesso
}

int remover ( Fila *p, int *info ){
	if( fila_vazia ( *p ) )
		return ERRO_FILA_VAZIA;
	
	*info = p->dados[p->inicio];
	p->inicio = (p->inicio + 1) % MAX;
	p->n--;
	return 1; // Sucesso
}

void mostra_fila ( Fila f ){
	if( fila_vazia ( f ) )
		printf("Fila vazia!\n");
	else{
		printf("Dados da fila:\n");
		int i, cont;

		for( cont = 0, i = f.inicio ; cont < f.n ; cont++, i = (i + 1) % MAX )
			printf("[%d] %d\n", i, f.dados[i]);
		
	}
	printf("\n");
}

void busca_largura(int dimensao, int tempValor, int noFinal, int noInicial, int **grafo){
	int achou = 0;
	Pilha p;
	Fila f;
	
	int *status_vertices = (int *) calloc(dimensao, sizeof(int));
    int *status_antecessores = (int *) calloc(dimensao, sizeof(int));
    
    noInicial = noInicial - 1;
	noFinal = noFinal - 1;
		
	inicializa_fila(&f);
	
	status_vertices[noInicial] = 1;
	 
	inserir(&f, noInicial);
	
	while(fila_vazia(f) != 1 && achou == 0){
		int i;
		
		remover(&f, &tempValor);
							
		if(tempValor == noFinal){
			achou = 1;
		}
		else
		{
			for (i = 0; i < dimensao; i++) {
				if(grafo[tempValor][i] == 1){
	                if (status_vertices[i] == 0) {
	                    status_vertices[i] = 1;
	                    status_antecessores[i] = tempValor;
	                    inserir(&f, i);
	                }
	            }
	    	}
		}
	}
	
	if(achou == 1){
		inicializa_pilha(&p,dimensao);
		while(tempValor != 0){
			empilha(&p,tempValor);
			tempValor = status_antecessores[tempValor];
		}
		while(pilha_vazia(p) != 1){
			desempilha(&p, &tempValor);
			printf("Ordem de passagem pelos vertices: %d \n",tempValor + 1);
		}
	}
	else{
		printf("B nao eh alcançavel a partir de A!");
	}
}


