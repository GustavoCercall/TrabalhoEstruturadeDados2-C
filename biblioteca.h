#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2
#define TAMANHO_PALAVRA 5

#define MAX 4

typedef struct{
   int *dados;        // dados da pilha 
   int topo;        // indica o ?ndice do topo
   int capacidade;    // capacidade do vetor alocado
} Pilha;

typedef struct{
   int dados[MAX]; // dados da fila 
   int inicio;     // ?ndice do in?cio da fila
   int n;          // qtd. de elementos da fila
} Fila;


void inicializa_pilha ( Pilha *p, int c );
int pilha_vazia ( Pilha p );
int pilha_cheia ( Pilha p );
int empilha ( Pilha *p, int info );
int desempilha ( Pilha *p, int *info );
void mostra_pilha ( Pilha p );
void desaloca_pilha( Pilha *p );

int **inicializa_grafo(int dimensao);
void mostra_grafo(int **grafo, int dimensao);

void inicializa_fila ( Fila *p );
int fila_vazia ( Fila f );
int fila_cheia ( Fila f );
int inserir ( Fila *p, int info );
int remover ( Fila *p, int *info );
void mostra_fila ( Fila f );



