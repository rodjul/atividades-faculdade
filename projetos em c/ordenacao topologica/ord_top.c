#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _TNo{
	int w;
	struct _TNo *prox;	
}TNo;
typedef struct{
	int V; // quantidade de vértices
	int A; // quantidade de arcos
	TNo **adj; //lista de adjacencia
}TDigrafo;


TDigrafo * Init( int V ); 
void insereA( TDigrafo *D, int v, int w);
void removeA(TDigrafo *D, int v, int w); 
void printAndRemoveAoutdeg(TDigrafo *D, int *visitado, int *imprmido, char tarefa[][256]);
void show(TDigrafo *D); 
void libera(TDigrafo *D); 
int indeg(TDigrafo *D, int v); 
int outdeg(TDigrafo *D, int v);
void busca(TDigrafo * G , char tarefa[][256], int *imprimido);
void Busca_Prof(TDigrafo *D, int *visitado, int *imprimido, int s, char tarefa[][256]);


char entrada[15] = "entrada.txt";

int main (void){
	setlocale(LC_ALL,"Portuguese"); //colocando a linguagem em portugues
	FILE *arq;
	int n_tarefas=0, m_pares=0;
	
	//le a primeira linha
	arq = fopen(entrada,"r");
	fscanf(arq,"%d",&n_tarefas);
	char tarefa[n_tarefas][256];

	//armazena no vetor as tarefas
	int i=0;
	while(i<n_tarefas)
		fscanf(arq,"%s",tarefa[i++]); 
	
	//le a 2 parte do arquivo, sequencias pares
	fscanf(arq,"%d",&m_pares);
	
	TDigrafo *digrafo;
	digrafo = Init(m_pares); //inicializando as posicoes requiridas de memoria
	
	//le os v-w e insere
	int v=0,w=0;
	while((fscanf(arq,"%d %d",&v,&w)) != EOF)
		insereA(digrafo,v,w);
	
	fclose(arq);


	show(digrafo);
	
	//faz uma verificação colocando o valor -1 nas posições que que precisa imprimir
	int *imprimido = (int*) calloc(digrafo->V, sizeof(int));
	for(i=0;i<digrafo->V;i++){
		TNo *aux = digrafo->adj[i];
		//se na posicao I do adj tiver algum nó, coloca -1
		if(aux!=NULL && !imprimido[i])
			imprimido[i] = -1;
		//verifica os proximos nos colocando -1
		while(aux){
			if(!imprimido[aux->w])
				imprimido[aux->w] = -1;
			aux = aux->prox;
		}
	}
		
	//utiliza as funcoes de busca profunda com modificacoes
	busca(digrafo, tarefa,imprimido);


	free(imprimido);
	libera(digrafo);

}

TDigrafo * Init( int V ){
	TDigrafo *D;
	int i;
	// aloca uma estrutura do tipo TDigrafo
	// http://www.cplusplus.com/reference/cstdlib/calloc/
	//printf("tamanho estrutura %d",sizeof(TDigrafo*));
	D = (TDigrafo *) calloc(1, sizeof(TDigrafo) );

	// D = new TDigrafo( V )
	// atribui o numero de vertices para a estrtura
	D->V = V;
	// zero numero arcos
	D->A = 0;
	// aloca as entradas para a lista de adjacencia
	D->adj = (TNo ** )calloc(V,sizeof(TNo*));
	
	return D;
	
}

void insereA( TDigrafo *D, int v, int w){
	// pega o inicio da lista a partir da entrada
	// do vertice v
	TNo *aux = D->adj[v];
	TNo *ant=NULL;
	
	//verifica se ja foi inserido um v-w
	TNo *inserida_anteriormente = aux;
	while(inserida_anteriormente){
		if(inserida_anteriormente->w == w){
			printf("Tarefas (%d,%d) ja inseridas!\n",v,w);
			return;
		}
		inserida_anteriormente = inserida_anteriormente->prox;
	}
	

	//verifica se o v-w forma um ciclo com w-v
	TNo *ciclo = NULL;
	ciclo = D->adj[w];
	while(ciclo){
		//if(ciclo->w == v || ciclo->w > w){ //v-w > w-v - na posicao w, o valor de W é maior que
		if(ciclo->w >= w){ //o valor do W-V é maior que o W-V? Ex: 1-2(v-w)  >=  3-1(v-w)
			printf("Tarefas (%d,%d) formam ciclos!\n",v,w);
			return;
		}
		ciclo = ciclo->prox;
	}
	
	
	while( aux && aux->w <= w ){
		// verifica se já existe o arco v-w
		if( aux->w == w)
			return;
		ant = aux;
		aux = aux->prox;

	}
	// so para testar vou inserir w no inicio de adj[v]
	TNo *novo = (TNo*)calloc(1,sizeof(TNo));
	novo->w = w;
	novo->prox = aux;
	if( ant ) // se existe anterior
		// insere no final
		ant->prox = novo;
	else
		// insere no inicio
		D->adj[v] = novo;
	
	(D->A)++;
}

void removeA(TDigrafo *D, int v, int w){
	TNo *aux = D->adj[v];
	TNo *ant=NULL;
	int boolAchou=0;
	// verifica se existe o arco v-w
	while(aux){
		if(aux->w == w)
			boolAchou=1; break; 
		ant = aux;
		aux = aux->prox;
	}
	if(boolAchou){
		if(ant == NULL)
			D->adj[v] = aux->prox;
		else
			ant->prox = aux->prox;
		(D->A)--;
	}

}

void printAndRemoveAoutdeg(TDigrafo *D, int *visitado, int *imprimido, char tarefa[][256]){
	int v;
	for(v=0; v<D->V; v++){
		if(visitado[v] && imprimido[v]==-1){ 
			//verifica se na posicao 0 do imprimido se tem -1
			//se não tiver, coloca uma posicao atras para que possa imprimir a tarefa na posicao certa do vetor
			int j=v;
			if(imprimido[0]==0)
				j = v-1;

			printf("\ntarefa  %d : %s", v, tarefa[j]);
			imprimido[v] = 1; //coloca como visitado
			int n_outdeg = outdeg(D,v);
			D->A = D->A - n_outdeg;
			
			//se for imprimido a maioria das tarefas ,o ultimo no nao vai ter ligacao(arestas),
			// entao procura no 'imprimido' se tem algum valor -1
			if(D->A == 0){
				for(j=0;j<D->V; j++){
					if(imprimido[j]==-1)
						printf("\ntarefa  %d : %s", j, tarefa[j-1]);
				}
			}
			
			free(D->adj[v]);
		}
	}
	
}

void show(TDigrafo *D){
	int v,w;
	
	for( v = 0; v < D->V; v++){ // vetor de listas
		printf("\n%d:",v);
		TNo *aux = D->adj[v];
		while( aux ){ // anda na lista
			printf(" %d",aux->w);
			aux = aux->prox;
		}
	}
}

void libera(TDigrafo *D){
	int i;
	for(i=0;i<D->V;i++)
		free(D->adj[i]); // desloca linha
	
	// desaloca matriz
	free( D->adj );
	
	// desaloca digrafo
	free( D );
	
}

int indeg(TDigrafo *D, int v){
	int grau=0,i=0;
	TNo *aux;
	while(i < D->V){
		aux=D->adj[i];
		while(aux){
			if(aux->w == v)
				grau++;
			aux=aux->prox;
		}
		if(aux == NULL)
			i++;
	}
	
	return grau;
}

int outdeg(TDigrafo *D, int v){
	int grau=0;
	TNo *aux = D->adj[v];
	while(aux){
		grau++;
		aux = aux->prox;
	}
	
	return grau;
}

void busca(TDigrafo * G , char tarefa[][256], int *imprimido){
	int *visitado = (int*) calloc(G->V, sizeof(int));

	int v;
	int i=0;
	//irá percorrer até não tiver mais nenhuma aresta disponível
	while(G->A){
		for(v=0;v<G->V; v++){
			// se v não foi visitado então
			if( !visitado[v] && indeg(G,v)==0)// && G->adj[v]!=NULL)
				Busca_Prof( G, visitado, imprimido, v, tarefa);	
		}
		//imprime as tarefas e diminui a quantidade de arestas
		printAndRemoveAoutdeg(G,visitado,imprimido,tarefa);
	}
	
	free(visitado);
}

/*
Dados vértices s e t de um digrafo G, decidir se existe ou não um caminho de s a t em G.  
Em outras palavras, decidir se o vértice t está ao alcance do vértice s em G.
*/
void Busca_Prof(TDigrafo *D, int *visitado, int *imprimido, int s, char tarefa[][256]){
	TNo *aux;

	// marca s como visitado
	visitado[s] = 1;
	
	aux =  D->adj[s];	
	while( aux ){
		// se aux->w nao foi visitado
		if (!visitado[aux->w] && indeg(D,aux->w)==0 )
			Busca_Prof(D, visitado,imprimido, aux->w, tarefa);

		aux = aux->prox;
	}
	
}

