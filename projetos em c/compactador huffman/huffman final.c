//Leonardo Irwin e Rodrigo Juliano

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _TNo{
	//lista encadeada
	char ch;
	int freq;
	struct _TNo *prox;
	//arvore
	int z;
	struct _TNo *esq;
	struct _TNo *dir;
	//prefixo binario
	char prefixo[9];
}TNo;

int QTDE_CHAR;
char arquivo_entrada[40];
char arquivo_bin[40];
char arquivo_descomp[40];

TNo * adicionaInicio(TNo *inicio, char ch, int freq);
TNo * adicionaOrdenado(TNo *inicio, char ch, int freq);
void adicionaArvCrescente(TNo *no, TNo *ini);
void insereQtdeLetraFile(TNo *inicio);
void definirPrefixoPosOrdem(TNo *raiz, int i, int bit, int *prefixo);
void inserePrefixoNo(TNo *raiz, int prefixo[],int i );
void imprimePrefixo(int prefixo[], int i);
void ordenaCrescLetraFile(TNo *ini_lista);
void insereLetraNumeroFile(TNo *raiz);
void insereBinarioFile(TNo *raiz);
void procuraLetraPosOrdem(TNo *raiz, char letra);
void converteBinarioFile(TNo *raiz, char arquivo[]);
void leArquivoBin();
void insereLetraDecodificado(char c);



int main(){
	
	while(1){
		char opcao;
		printf("O que deseja fazer?\n");
		printf("1 - Compactar arquivo\n");
		printf("2 - Descompactar arquivo\n");
		printf("0 - Sair\n");
		printf("Opcao: ");
		scanf("\n%c",&opcao);
		if(opcao == '0')
			exit(1);
		if(opcao == '1'){
			
			printf("\n");
			printf("Insira o nome do arquivo: ");
			scanf("\n%[^\n]s",&arquivo_entrada);

			
			char saida[8] = "_bin.txt";
			char bin_file[20];
			int letra=0;
			while(1){
				if(arquivo_entrada[letra] == '.'){
					int letra_2=0;
					while(1){
						if(letra_2 == 8)
							break;
						else
							bin_file[letra] = saida[letra_2];
						letra_2++;
						letra++;
					}
					break;
				}				
				else
					bin_file[letra] = arquivo_entrada[letra];
				letra++;
			}
			strcpy(arquivo_bin,bin_file);
			
			
			
			//compactacao
			int tabela_freq [256] = {0}; //inicializa com 0 os espaços 

			
			//char arquivo[] = "entrada.txt";
			FILE *arq;
			arq = fopen(arquivo_entrada,"r");

			
			int i;
			//le o arquivo de entrada e coloca as frequencia de numeros na tabela freq
			char c;
			while( (fscanf(arq,"%c",&c)) != EOF){
				int ascii_c = c; //converte para ascii
				tabela_freq[ascii_c] = tabela_freq[ascii_c] + 1;
				
			}
			fclose(arq);
		
			
			// lista encadeada
			TNo *ini;
			ini = 0;
			
			for(i=0; i<256; i++){
				if(tabela_freq[i]!=0){
					c = i;
					ini = adicionaOrdenado(ini, c, tabela_freq[i]);	
				}
			}
			
			insereQtdeLetraFile(ini);
			ordenaCrescLetraFile(ini);
			
			
			//arvore
			
			TNo *no, *tempIni;
			no = 0;
			tempIni = ini;
			
			while(tempIni){
				no = (TNo *) calloc(1,sizeof(TNo));
		
				no->esq = tempIni;
				
				tempIni = tempIni->prox;
				
				no->dir = tempIni;
		
				
				no->z 	= no->esq->freq + no->dir->freq;
				no->freq = no->z;
				
				if(tempIni->prox == 0) //dps de somar os 2 ultimos nos, o proximo eh nulo entao para o while
					break;
				
				adicionaArvCrescente(no, tempIni);
				
				tempIni = tempIni->prox;
				
			}
			
			int prefixo[9];
			definirPrefixoPosOrdem(no, 0, -1, prefixo); //primeira posicao n usa, sobra 8
			
					
			converteBinarioFile(no,arquivo_entrada);
		
			printf("Arquivo compactado foi gerado como: %s\n",arquivo_bin);
			
		}else 
		if(opcao == '2'){
			printf("\n");
			printf("Insira o nome do arquivo: ");
			scanf("\n%[^\n]s",&arquivo_entrada);
			
			char descompatado[12] = "_descomp.txt";
			char bin_file[20];
			int letra=0;
			while(1){
				if(arquivo_entrada[letra] == '.'){
					int letra_2=0;
					while(1){
						if(letra_2 == 12)
							break;
						else
							bin_file[letra] = descompatado[letra_2];
						letra_2++;
						letra++;
					}
					break;
				}				
				else
					bin_file[letra] = arquivo_entrada[letra];
				letra++;
			}
			strcpy(arquivo_descomp,bin_file);
			
			
			leArquivoBin(); //le o arquivo bin e descompacta
			
			printf("Arquivo descompactado foi gerado como: %s\n",arquivo_descomp);

		}
		printf("\n");
		
	}
	
	

	
	
	
	
	
	return 0;
}

TNo * adicionaOrdenado(TNo *inicio, char ch, int freq){
	TNo *atual, *anterior, *novo, *tempAtual;
		
	if(inicio == 0){		
		return adicionaInicio(inicio,ch,freq);
	}
	
		
	anterior = 0;
	atual = inicio;

	
	while(atual){
		if(atual->freq < freq){
			anterior = atual;
		}
		atual = atual->prox;
	}
	
	novo = (TNo *) calloc(1,sizeof(TNo));
	novo->ch = ch;
	novo->freq = freq;
	

	if(anterior == 0){

		novo->prox = inicio;
		inicio = novo;
	}else{

		tempAtual = anterior->prox;
		anterior->prox = novo;
		novo->prox = tempAtual;
		
	}
	
	
	return inicio;
	
}

TNo * adicionaInicio(TNo *inicio, char ch, int freq){
	TNo *novo = (TNo *) calloc(1,sizeof(TNo));
	novo->ch = ch;
	novo->freq = freq;
	
	novo->prox = inicio;
	inicio = novo;
	
	return inicio;
}

void adicionaArvCrescente(TNo *no, TNo *ini){
	TNo *anterior, *atual;
	atual = ini;

	while(atual->freq < no->z && atual->prox != 0) {
		anterior = atual;
		atual = atual->prox;	
	}
	
	if(atual->prox == 0){
		if(no->z > atual->freq){
			atual->prox = no;
		}else{
			anterior->prox = no;
			no->prox = atual;	
		}
	}else{
		anterior->prox = no;
		no->prox = atual;
	}

}

void insereQtdeLetraFile(TNo *inicio){ 
	int count = 0;
	while(inicio){
		//printf("%d %c %d\n",count,inicio->ch,inicio->freq );
		inicio = inicio->prox;
		count++;
	}
	QTDE_CHAR = count;
	
	FILE *arqBin;
	arqBin = fopen(arquivo_bin,"w+");
	fprintf(arqBin,"%d\n",count);
	
	fclose(arqBin);
}

void definirPrefixoPosOrdem(TNo *raiz, int i, int bit, int prefixo[]){
	if(raiz != 0){
		prefixo[i] = bit;
		definirPrefixoPosOrdem(raiz->esq, i+1, 0, prefixo);
		definirPrefixoPosOrdem(raiz->dir, i+1, 1, prefixo);
		if(raiz->ch != 0){
			inserePrefixoNo(raiz,prefixo,i);
		}
		
	}
		
}

//armazenar o prefixo na variavel prefixo
//https://stackoverflow.com/questions/30234363/how-can-i-store-an-int-array-into-string
void inserePrefixoNo(TNo *raiz, int prefixo[],int i ){
	char str[9];
	int n=0;
	int j;
	for(j=1; j<=i; j++){
		char c = prefixo[j] + '0';
		n += sprintf(&str[n],"%d",prefixo[j]);
	}

	strncpy(raiz->prefixo, str,9);

}

void imprimePrefixo(int prefixo[], int i){
	int j;
	for(j=1;j<=i;j++){
		printf("\n%d",prefixo[j]);
	}
}

//ordena o vetor em ordem crescente do alfabeto para escrever no arquivo de saida
void ordenaCrescLetraFile(TNo *ini_lista){
	TNo *reset;
	reset = ini_lista;
	char letra[QTDE_CHAR];
	int i;
	
	while(i<QTDE_CHAR){
		letra[i] = ini_lista->ch;
		ini_lista = ini_lista->prox;
		i++;
	}
	// ordena as letras em ordem crescente
	int j;
	char aux;
	int k = QTDE_CHAR-1;
	for(i=0;i<QTDE_CHAR;i++){
		for(j=0;j<k; j++){
			if(letra[j] > letra[j+1]){
				aux = letra[j];
				letra[j] = letra[j+1];
				letra[j+1] = aux;
			}
		}
	
	}
	
	i=0;
	ini_lista = reset;
	while(ini_lista && i<QTDE_CHAR){
		if(ini_lista->ch == letra[i]){
			insereLetraNumeroFile(ini_lista);
			ini_lista = reset;
			i++;
		}else
			ini_lista = ini_lista->prox;		
	}
	
	
}

void insereLetraNumeroFile(TNo *raiz){
	FILE *saidaBin;
	saidaBin = fopen(arquivo_bin,"a+");
	
	fprintf(saidaBin,"%c:%d ",raiz->ch,raiz->freq);	
	
	fclose(saidaBin);
}

void insereBinarioFile(TNo *raiz){
	FILE *saidaBin;
	saidaBin = fopen(arquivo_bin,"a+");
	
	fprintf(saidaBin,"%s",raiz->prefixo);	
	
	fclose(saidaBin);
}

void procuraLetraPosOrdem(TNo *raiz, char letra){
	if(raiz != 0){
		procuraLetraPosOrdem(raiz->esq, letra);
		procuraLetraPosOrdem(raiz->dir, letra);
		if(raiz->ch!=0 && raiz->ch == letra)
			insereBinarioFile(raiz);
	}
}

void converteBinarioFile(TNo *raiz, char arquivo[]){
	FILE *arq;
	char c;
	arq = fopen(arquivo,"r");
	while((fscanf(arq,"%c",&c)) != EOF ){
		procuraLetraPosOrdem(raiz,c);
	}
	
}


void leArquivoBin(){
	FILE *arq;
	char c;
	int freq=0,qtd, passou=0;
	TNo *inicio;
	inicio = 0;
	
	arq = fopen(arquivo_entrada,"r");
	fscanf(arq,"%d",&qtd); //quantidade de letras
	while( (fscanf(arq,"%c:%d",&c,&freq)) != EOF && qtd!=0){
		if(c==32 && freq>0 && passou!=1){ //verifica se contem espaços no texto, o ascii space vem primeiro
			inicio = adicionaOrdenado(inicio,c,freq);
			qtd--;
			passou = 1;
		}
		if(isalpha(c) && freq>0){
			inicio = adicionaOrdenado(inicio,c,freq);
			qtd--;
		}
		freq=0;
	}
	
	
	//arvore
	TNo *no, *tempIni;
	no = 0;
	tempIni = inicio;
	
	while(tempIni){
		no = (TNo *) calloc(1,sizeof(TNo));

		no->esq = tempIni;
		tempIni = tempIni->prox;
		no->dir = tempIni;

		no->z 	= no->esq->freq + no->dir->freq;
		no->freq = no->z;
		
		if(tempIni->prox == 0) //dps de somar os 2 ultimos nos, o proximo eh nulo entao para o while
			break;
		
		adicionaArvCrescente(no, tempIni);		
		tempIni = tempIni->prox;
		
	}
	char bit;
	
	//estilo pos ordem, procura o no de acordo com o numero e imprime a letra
	while( (fscanf(arq,"%c",&bit) ) != EOF)	{
	
		TNo *temp;
		temp = no;
		while(temp != 0){
			if(bit == '0'){
				temp = temp->esq;
			}else if(bit == '1'){
				temp = temp->dir;
			} 
			if(temp->esq == 0 && temp->dir == 0){
				//printf("%c",temp->ch);
				insereLetraDecodificado(temp->ch);
				break;
			}
			bit = fgetc(arq);
		}
		
	}
	
	fclose(arq);
	
}

void insereLetraDecodificado(char c){
	FILE *f;
	f = fopen(arquivo_descomp,"a+");
	if(f == NULL){
		f = fopen(arquivo_descomp,"w+");
	}
	fprintf(f,"%c",c);
	fclose(f);
}
