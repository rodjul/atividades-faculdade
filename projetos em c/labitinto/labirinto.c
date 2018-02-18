//Rodrigo Juliano
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	int visitado;
	int valor; 
}Coordenada;

typedef struct{
	int size;
	Coordenada **adj;
}Matriz;


Matriz * init(int size);
void insere(FILE *f, Matriz *m);
void libera(Matriz *m);
void show(Matriz *m);
void menorCaminho(Matriz *m, Coordenada *pontoA, Coordenada *pontoB);
Coordenada * acima(int x, int y);
Coordenada * abaixo(int x, int y);
Coordenada * esquerda(int x, int y);
Coordenada * direita(int x, int y);
int ehParede(Matriz *m, Coordenada *c);
int ehParede(Matriz *m, Coordenada *c);
int naoFoiVisitado(Matriz *m, Coordenada *c);
void colocaNaFila(Matriz *m, Coordenada *aux, Coordenada *fila, Coordenada *ponto);
void numerarVizinhos(Matriz *m, Coordenada *ponto, Coordenada *fila);

char entrada[15] = "entrada.txt";
int i_fila = 0; //controle da fila
int j_fila = 0; //controle da fila
Coordenada *pontoA, *pontoB;

void main(void){
	FILE *f;
	int size;
	int valor;

	f = fopen(entrada,"r");
	fscanf(f,"%d",&size);
	
	Matriz *matriz;
	
	matriz = init(size);
	insere(f,matriz);
	fclose(f);
	
	//show(matriz);
	
	//colocando valores nos pontos A e B
	int x,y,parede=1;
	pontoA = (Coordenada *) calloc(1,sizeof(Coordenada));
	pontoB = (Coordenada *) calloc(1,sizeof(Coordenada));

	while(parede){
		printf("Insira o valor X do ponto A: \n");
		scanf("\n%d",&x);
		printf("Insira o valor Y do ponto A: \n");
		scanf("\n%d",&y);
		
		if( (x-1<0 || y-1<0) || (x-1>=matriz->size || y-1>=matriz->size) )
			printf("Posicao inv
			alida, insira novamente um valor maior ou igual a 1 ou menor ou igual a %d\n",matriz->size);
		else if( matriz->adj[x-1][y-1].valor == -1 && x>=0 && y>=0 ){
			printf("Posicao inserida eh parede, insira novamente\n");
		}else{
			pontoA->x = x-1;
			pontoA->y = y-1;
			pontoA->visitado = 0;
			matriz->adj[ pontoA->x ][ pontoA->y ] = *pontoA;
			parede = 0;
		}
	}
	parede=1;
	while(parede){
		printf("Insira o valor X do ponto B: \n");
		scanf("\n%d",&x);
		printf("Insira o valor Y do ponto B: \n");
		scanf("\n%d",&y);
		
		if( (x-1<0 || y-1<0) || (x-1>=matriz->size || y-1>=matriz->size) )
			printf("Posicao invalida, insira novamente um valor maior ou igual a 1 ou menor ou igual a %d\n",matriz->size);
		else if( matriz->adj[x-1][y-1].valor == -1 ){
			printf("Posicao inserida eh parede, insira novamente\n");
		}else{
			pontoB->x = x-1;
			pontoB->y = y-1;
			pontoB->visitado = 0;
			matriz->adj[ pontoB->x ][ pontoB->y ] = *pontoB;
			parede = 0;
		}
	}
	
	
	/*
	pontoA->x=3; //x=3 -1
	pontoA->y=1; //y=2 -1
	pontoA->visitado=0; 
	
	pontoB->x=4; //x=5 -1
	pontoB->y=5; //y=6 -1
	pontoB->visitado=0;  
	//coloca a coordenada pontos com os valores inicializados na matriz
	matriz->adj[ pontoA->x ][ pontoA->y ] = *pontoA;
	matriz->adj[ pontoB->x ][ pontoB->y ] = *pontoB;
	*/
	
	printf("Ponto A - X:%d Y:%d\n",pontoA->x + 1, pontoA->y + 1);
	printf("Ponto B - X:%d Y:%d\n",pontoB->x + 1, pontoB->y + 1);
	
	menorCaminho(matriz, pontoA, pontoB);
	
	printf("\n\nValores da matriz\n");
	show(matriz);

	free(pontoA);
	free(pontoB);
	libera(matriz);
	
}

//inicializa a matriz
Matriz * init(int size){
	Matriz *m;
	int i;
	m = (Matriz *) calloc(1,sizeof(Matriz));
	m->size = size;
	m->adj = (Coordenada **) calloc(size, sizeof(Coordenada*));
	for(i=0;i<size;i++)
		m->adj[i] = (Coordenada *) calloc(size, sizeof(Coordenada));
	
	return m;
	
}

//imprime o formato da matriz
void show(Matriz *m){
	int i,j;
	Coordenada *aux;
	for(i=0;i<m->size;i++){
		for(j=0;j<m->size;j++){
			aux = m->adj[i];
			if(aux[j].valor == -1)
				printf("-1   ");
			else
				printf("%d    ",aux[j].visitado);
			
			if(j+1==m->size) printf("\n");
		}
	}
}

//insere na matriz os valores das coordenadas nas posicoes i e j da matriz
void insere(FILE *f, Matriz *m){
	int i=0,j=0, valor;
	while(i<m->size){
		while((fscanf(f,"%d",&valor)) != EOF){
			Coordenada *ponto;
			ponto = (Coordenada *) calloc(1,sizeof(Coordenada));
			ponto->x = i;
			ponto->y = j;
			ponto->valor = valor; //valor do arquivo txt
			ponto->visitado = 0;
			m->adj[i][j] = *ponto;
			j++;
			if(j==m->size)
				break;
		}
		j=0;
		i++;
	}

}

Coordenada * acima(int x, int y){
	Coordenada *aux;
	aux = (Coordenada *) calloc(1,sizeof(Coordenada));
	aux->x = x-1;
	aux->y = y;
	return aux;
}
Coordenada * abaixo(int x, int y){
	Coordenada *aux;
	aux = (Coordenada *) calloc(1,sizeof(Coordenada));
	aux->x = x+1;
	aux->y = y;
	return aux;
}
Coordenada * esquerda(int x, int y){
	Coordenada *aux;
	aux = (Coordenada *) calloc(1,sizeof(Coordenada));
	aux->x = x;
	aux->y = y-1;
	return aux;
}
Coordenada * direita(int x, int y){
	Coordenada *aux;
	aux = (Coordenada *) calloc(1,sizeof(Coordenada));
	aux->x = x;
	aux->y = y+1;
	return aux;
}

int ehParede(Matriz *m, Coordenada *c){
	return m->adj[c->x][c->y].valor == -1;
}

int naoFoiVisitado(Matriz *m, Coordenada *c){
	//verifica se a coordenada atual nao eh o valor do pontoA e se nao foi visitado
	return !(c->x == pontoA->x && c->y == pontoA->y) && m->adj[c->x][c->y].visitado == 0 ;
}

int estaNoRangeDaMatriz(Coordenada *c, Matriz *m){
	return (c->x>=0 && c->x<m->size) && (c->y>=0 && c->y<m->size);
}

void colocaNaFila(Matriz *m, Coordenada *aux, Coordenada *fila, Coordenada *ponto){
	//verifica se a posicao atual do AUX nao ultrapassa os limites da matriz 
	//verifica se nao ehParede na posicao atual da matriz e se naoFoiVisitado
	if( estaNoRangeDaMatriz(aux,m) && !ehParede(m,aux) && naoFoiVisitado(m,aux) )
	{
		//se nao foi visitado e nao eh parede, pega o valor do ponto atual e soma +1
		aux->visitado = ponto->visitado + 1;
		//coloca na fila para preencher a matriz e atualiza a variavel global j_fila
		fila[j_fila++] = *aux;
		//atualiza o valor da coordenada na matriz
		m->adj[aux->x][aux->y] = *aux;
	}
}

void numerarVizinhos(Matriz *m, Coordenada *ponto, Coordenada *fila){
	Coordenada *aux;
	//obtem os valores das posicoes vizinhas da matriz e usa a funcao colocaNaFila
	if(!ehParede(m,ponto)){
		aux = acima(ponto->x,ponto->y);
		colocaNaFila(m,aux,fila,ponto);
		
		aux = abaixo(ponto->x,ponto->y);
		colocaNaFila(m,aux,fila,ponto);

		aux = esquerda(ponto->x,ponto->y);
		colocaNaFila(m,aux,fila,ponto);

		aux = direita(ponto->x,ponto->y);
		colocaNaFila(m,aux,fila,ponto);
	}

}

void menorCaminho(Matriz *m, Coordenada *pontoA, Coordenada *pontoB){
	Coordenada *aux;
	int N = m->size * m->size;
	//variavel fila ira colocar as posicoes das coordenadas para preencher a matriz
	Coordenada *fila = (Coordenada *) calloc(N,sizeof(Coordenada));
	
	//numerando vizinhos do pontoA
	aux = acima(pontoA->x,pontoA->y);
	colocaNaFila(m,aux,fila,pontoA);

	aux = abaixo(pontoA->x,pontoA->y);
	colocaNaFila(m,aux,fila,pontoA);
	
	aux = esquerda(pontoA->x,pontoA->y);
	colocaNaFila(m,aux,fila,pontoA);
	
	aux = direita(pontoA->x,pontoA->y);
	colocaNaFila(m,aux,fila,pontoA);
	
	
	Coordenada *ponto;
	//variavel ponto como auxiliar
	ponto = (Coordenada *) calloc(1,sizeof(Coordenada));
	//enquanto fila nao estiver cheia
	while(!(i_fila==j_fila)){
		//retira um elemento da fila
		*ponto = fila[i_fila++];
		//coloca valor nos vizinhos
		numerarVizinhos(m,ponto,fila);	
	}
	
	//show(m);
	
	//verificando o menor caminho a partir de B
	i_fila=0;
	j_fila=0;
	int k=1;
	Coordenada *posAcima,*posBaixo,*posEsquerda,*posDireita, *temp, *menor;
	//variavel caminho que sera usado para obter o caminho
	Coordenada *caminho = (Coordenada *) calloc(N,sizeof(Coordenada));

	menor = (Coordenada *) calloc(1,sizeof(Coordenada));
	temp = (Coordenada *) calloc(1,sizeof(Coordenada));
	//comeca o temp com o valor da coordenada pontoB
	temp->x = pontoB->x;
	temp->y = pontoB->y;


	int i_menor=0;
	//a partir do pontoB, percorrer a matriz ate chegar no pontoA
	while(!(caminho[k-1].x == pontoA->x && caminho[k-1].y == pontoA->y)){
		//obtem os valores dos vizinhos
		posAcima = acima(temp->x,temp->y); 
		posBaixo = abaixo(temp->x,temp->y); 
		posEsquerda = esquerda(temp->x,temp->y); 
		posDireita = direita(temp->x,temp->y);
		

		if ( estaNoRangeDaMatriz(posAcima,m) && !(ehParede(m,posAcima)) )
			caminho[j_fila++] = m->adj[posAcima->x][posAcima->y];
			
		if( estaNoRangeDaMatriz(posBaixo,m) && !(ehParede(m,posBaixo)) )
			caminho[j_fila++] = m->adj[posBaixo->x][posBaixo->y];
			
		if( estaNoRangeDaMatriz(posEsquerda,m) && !(ehParede(m,posEsquerda)) ) 
			caminho[j_fila++] = m->adj[posEsquerda->x][posEsquerda->y];
			
		if( estaNoRangeDaMatriz(posDireita,m) && !(ehParede(m,posDireita)) ) 
			caminho[j_fila++] = m->adj[posDireita->x][posDireita->y];
		
		//coloca como menor caminho a ultima posicao colocada para fazer a verificacao
		*menor = caminho[j_fila-1];
		//percorre o caminho com os valores obtidos anteriormente
		while(i_fila<j_fila){
			//verifica se na posicoa atual do caminho eh menor que o valor da variavel menor
			if(caminho[i_fila].valor != -1 && caminho[i_fila].visitado < menor->visitado )
				//atualiza a variavel menor com o menor valor obtido
				*menor = caminho[i_fila];
			
			i_fila++;

			//se chegar no fim da fila caminho
			if(i_fila==j_fila){
				//atualiza a variavel caminho na posicao k e tira N-k do tamanho do caminho
				caminho[k++] = *menor;
				//atualiza a variavel temp com a coordenada obtida
				*temp = caminho[k-1];
				//reseta as variaveis da fila com o tamanho k
				i_fila=k;
				j_fila=k;
				//printf("(%d,%d) \n",caminho[k-1].x,caminho[k-1].y );
			}
		}
	}
	

	printf("Caminho: ");
	while(k>1){
		printf("(%d,%d) ",caminho[k-1].x + 1,caminho[k-1].y + 1);
		k--;
	}
	printf("(%d,%d) ",pontoB->x + 1,pontoB->y + 1);
	
	free(temp);
	free(caminho);
	free(menor);
	free(ponto);
	free(aux);
	free(fila);
}

void libera(Matriz *m){
	int i;
	for(i=0;i<m->size;i++)
		free(m->adj[i]);
	free(m->adj);
	free(m);
}

