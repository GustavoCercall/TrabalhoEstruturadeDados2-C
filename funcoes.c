void busca_largura(int dimensao, int tempValor, Fila f, ){
	int achou = 0;
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
