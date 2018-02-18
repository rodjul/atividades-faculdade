//Leonardo Irwin e Rodrigo Juliano
#include <stdio.h>

int seq=1;
int *ladoA[50];
int *ladoB[50];
int conseguiuAdicionar = 0;
int naoConseguiuColocar = 0;

void permuta(int S[], int i, int A[], int N, int tempoTotalSeg){
    int j;
    if( i == N ) // i == N
	  imprima(S,N,tempoTotalSeg);
    else
      for(j=0; j<N;j++){ // N
        S[i]=A[j];
        if(valida(S,i,tempoTotalSeg))//determina se uma solução parcial é promissora 
	    	permuta(S, i+1, A, N, tempoTotalSeg);
      }
}

int valida(int S[], int i, int tempoTotalSeg){
	int j;
	for( j = 0; j < i; j++){
		if( S[j]==S[i]){
			return 0;//false, nao eh promissor
		}
		if(S[j] >= tempoTotalSeg){
			return 0;
		}
	}

	return 1; // true, eh promissora	

}

void verificaLado(int v[],int N, int tempoTotalSeg){
	int somaTotal =0, somaLadoA=0, somaLadoB=0;
	int entrou=0,i,j=0,k=0;
	conseguiuAdicionar = 0;
	
	for(i=0; i<N; i++){
		if(v[i]<=(tempoTotalSeg/2)){
			somaTotal += v[i];			
			
			if(somaTotal<=(tempoTotalSeg/2)){
				somaLadoA += v[i];
				if(somaLadoA<=(tempoTotalSeg/2)){
					ladoA[k] = v[i];
					k++;
					conseguiuAdicionar++;
										
				}else{
					somaLadoA -= v[i];
				}
				
			}else{
				somaLadoB += v[i];
				if(somaLadoB<=(tempoTotalSeg/2)){
					ladoB[j] = v[i];
					j++;
					conseguiuAdicionar++;
				
				}else{
					somaLadoB -= v[i];
				}
			}
		}
	}
	
}

void imprima( int v[], int N, int tempoTotalSeg){
	verificaLado(v,N,tempoTotalSeg);
	if(conseguiuAdicionar == N){
	
	    int i;
	    printf("%d) \n",seq);
	    seq++;
	    printf("Lado A: \n");
	    for( i=0; i < N; i++){
	        imprimeMinutosSegundos(ladoA[i]);
		}
		printf("\n");
		printf("Lado B: \n");
		for(i=0; i< N; i++){
			imprimeMinutosSegundos(ladoB[i]);
		}
	    printf("\n");
	    
	    naoConseguiuColocar = 0; //false
	}else{
		naoConseguiuColocar = 1; //true
	}
	
	limpaPonteiro();

	
	
}

void limpaPonteiro(){
	int i;
	for(i=0;i<10;i++){
		ladoA[i] = 0;
		ladoB[i] = 0;
	}
}

int converteMinSegundos(int min, int seg){
	return min*60 + seg;
}

void imprimeMinutosSegundos(int seg){
	if(seg != 0){
		int minutos  = seg/60;
		int segundos = seg - (minutos*60);
		printf("%dm %ds\n",minutos,segundos);
	}
}

int main(){


	char arquivo[] = "entrada.txt";
	
	int qtdeTeste, tempoTotalMin, qtdeMusica, tempoTotalSeg;
	int coluna1, coluna2, i=0;
	int caso = 0;
	FILE *arq;
	
	arq = fopen(arquivo, "r");
	fscanf(arq, "%d",&qtdeTeste); //le a primeira linha para saber qtde de testes	
	
	while(caso<qtdeTeste){
	
		fscanf(arq, "%d %d",&tempoTotalMin,&qtdeMusica); //le a segunda linha para saber o tempo e qtde musica
		
		tempoTotalSeg = tempoTotalMin * 60;
		int musicas[qtdeMusica];
	
		
		while( (fscanf(arq, "%d %d", &coluna1,&coluna2)) != EOF){ //le o resto das linhas
			musicas[i] = converteMinSegundos(coluna1, coluna2);
			i++;
			if(i == qtdeMusica)
				break;
		}
		i=0; //reseta o indice do vetor musicas	
		
				
		
		int S[qtdeMusica];
		
		
		printf("Caso %d Tempo:%d min\n",(caso+1), tempoTotalMin);
		
		permuta(S,0,musicas,qtdeMusica, tempoTotalSeg);
		if(naoConseguiuColocar == 1 && seq ==1){
			printf("Impossivel gravar todas as musicas nessa fita \n");
		}
		
		caso++;
		seq = 1;
		printf("\n");
	}
	
	fclose(arq);
	
	

	
	return 0;
}

