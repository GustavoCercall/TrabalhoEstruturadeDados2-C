#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "portuguese");
    
    int **grafo;
    int dimensao;
    int noInicial, noFinal,  tempValor = 0;
    
    
    printf("Digite a dimensão do grafo:\n");
    scanf("%d", &dimensao);
    
    grafo = inicializa_grafo(dimensao);
    
    mostra_grafo(grafo, dimensao);
    
    printf("Onde deseja começar a busca:\n");
    scanf("%d", &noInicial);
    
    printf("Ponto final do percurso:\n");
    scanf("%d", &noFinal);
	
	busca_largura(dimensao, tempValor, noFinal, noInicial, grafo);
	
	return 0;
}
