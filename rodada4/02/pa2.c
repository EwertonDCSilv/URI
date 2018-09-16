#include <stdio.h>
#include <stdlib.h>

typedef struct Celula* PonteiroPraCelula ;
struct Celula{
	int id_vizinho;
	int peso;
	PonteiroPraCelula Prox;
}Celula;

typedef struct lista{
	int vistiado;
	PonteiroPraCelula Primeiro, Ultimo ;
}LISTA;

typedef struct grafo{
	int num_nos;
	LISTA *VetLista;
}GRAFO;

void CriaLista(LISTA *lista);
void InsereLista(int id_vizinho, int peso, LISTA *lista);

void CriaGrafo(int N,GRAFO *Grafo);
void InsereAresta(int V1, int V2, int peso, GRAFO *Grafo);
void LiberaGrafo(GRAFO *Grafo);
	
int primMSTT(GRAFO *g, int p[], int w[]);
		
int main (int argc, char* argv[]){

	int L=0,N=0,M=0;
	int i=0,id=0;
	int resp = 0;
	int id_1=0,id_2=0,peso=0;
	GRAFO Grafo;
	PonteiroPraCelula Aux;
	
	while(1){
		if((scanf("%i %i",&N,&M)) != 2)//Verifica se a entrada foram recebidos com sucesso
			break;
		
		CriaGrafo(N,&Grafo);//Cria a estrutura do tipo grafo
			
		for(i=0;i<M;i++){
			
			//Recebe a relacao
			if(scanf(" %i %i %i",&id_1,&id_2,&peso) !=3)
				break;
			
			//printf("ID1: %i\tID2: %i\tPeso: %i\n\n",id_1,id_2,peso);
						
			InsereAresta(id_1-1,id_2-1,peso,&Grafo);//Cria a relacao de ida  0 a N-1
			InsereAresta(id_2-1,id_1-1,peso,&Grafo);//Cria a relacao de volta
		}
		int p[N],w[M];//Cria vetores
		
		for(i=0;i<N;i++)
			w[i] = -1;
		
		for(i=0;i<M;i++)
			w[i] = -1;
		
		primMSTT(&Grafo,p,w);

		for(i=0;i<M;i++)//Calculo o peso final
			if(w[i] != -1)
				resp = resp + w[i];
			
		printf("%i\n",resp);
	
		LiberaGrafo(&Grafo);//Desalocando a Memoria usada pelo Grafo
		resp = 0;
	}
	return 0;
}

//________ Funcao que cria a lista de adjacencia ________//
void CriaLista(LISTA *lista){//Complexidade O = (1)
	lista->Primeiro = (PonteiroPraCelula)malloc(sizeof(Celula));//Aloca memoria para um ponteira para celula
	lista->Ultimo = lista->Primeiro;//O ultimo aponto para o primeiro ja que a lista esta vazia
	lista->Primeiro->Prox = NULL;
}

//________ Funcao que insere dados na lista ________//
void InsereLista(int id_vizinho,int peso, LISTA *lista){//Complexidade O = (1)
	lista->Ultimo->Prox = (PonteiroPraCelula)malloc(sizeof(Celula));//Aloca memoria para um ponteira para celula
	lista->Ultimo = lista->Ultimo->Prox;
	lista->Ultimo->id_vizinho = id_vizinho;//Insere o id da vertice adjacente
	lista->Ultimo->peso = peso;//Insere o peso da relacao
	lista->Ultimo->Prox = NULL;//Define como nulo o apontador para o proximo
}

//________ Funcao que cria o grafo ________//
void CriaGrafo(int N,GRAFO *Grafo){//Complexidade O = (N)
	int i = 0;
	Grafo->VetLista = (LISTA*)malloc((N)*(sizeof(LISTA)));//Aloca memoria para o vetor da lista de adjacencia
	Grafo->num_nos = N;//Define o Numero de vertices do Grafo
	for(i = 0; i < Grafo->num_nos; i++)
		CriaLista(&Grafo->VetLista[i]);//Realiza a chamada da funcao que cria as celulas da lista
}

//________ Funcao que cria uma areasta entre dois nos do grafo ________//
void InsereAresta(int V1, int V2, int peso, GRAFO *Grafo){//Complexidade O = (1)
	Grafo->VetLista[V1].vistiado = -1;//Incializa a propriedade como 0
	InsereLista(V2,peso,&Grafo->VetLista[V1]);//Insere vizinho na lista de Adjacencia
}

//________ Funcao da arvore geradora minima ________//
int primMSTT(GRAFO *g, int p[], int w[]) {
	
	int i, imin, v, r=0, cor[g->num_nos];
	PonteiroPraCelula aux;
	int fsize=0, fringe[g->num_nos]; // ORLA (stack de vértices)
	int WHITE = 1, GREY = -1, BLACK = 0;
	
	for (i=0; i<g->num_nos; i++) {
		p[i] = -1;
		cor[i] = WHITE;
	}
	
	cor[0] = GREY;
	w[0] = 0;
	fringe[fsize++] = 0;
	
	while (fsize>0) {

		imin = 0;
		for (i=1; i<fsize; i++)
			if (w[fringe[i]] < w[fringe[imin]]) 
				imin = i;

		v = fringe[imin];
		fringe[imin] = fringe[--fsize];

		cor[v] = BLACK;
		r += w[v];
		
		aux = g->VetLista[v].Primeiro->Prox;
		
		while(aux != NULL){
			if(cor[aux->id_vizinho] == WHITE){
				cor[aux->id_vizinho] = GREY;
				fringe[fsize++] = aux->id_vizinho;
				w[aux->id_vizinho] = aux->peso;
				p[aux->id_vizinho] = v;
			
			}if(cor[aux->id_vizinho] == GREY){
				if (aux->peso < w[aux->id_vizinho]){
					p[aux->id_vizinho] = v;
					w[aux->id_vizinho] = aux->peso;
				}
			}
			aux = aux->Prox;//Recebe o apontador para o proximo da lista
		}
	}
	return r;
}

//________ Funcao que libera o grafo da memoria ________//
void LiberaGrafo(GRAFO *Grafo){//Complexidade O = (N + M)
	int i=0;
	PonteiroPraCelula AuxAnterior, Aux;
	for(i = 0; i < Grafo->num_nos; i++){//Executa Para todos os N indices da lista
		Aux = Grafo->VetLista[i].Primeiro->Prox;
		free(Grafo->VetLista[i].Primeiro);//Libera o apontador para a Celula
		while(Aux != NULL){//Executa enquanto existir elementos
			AuxAnterior = Aux;
			Aux = Aux->Prox;
			free(AuxAnterior);//Libera o apontador para a Celula
		}
	}
	free(Grafo->VetLista);//Libera o vetor da lista
	Grafo->num_nos = 0;	
}

/*
*	URI Online Judge | 1774
*	Roteadores
*	Por Carlos Andrade, UFMS BR Brazil
*	
*	Timelimit: 4
*	Bruno é o responsável por configurar os roteadores de uma empresa. Os roteadores transmitem os dados entre si através dos cabos de internet, Os dados transmitidos podem trafegar por uma ou mais rotas para serem entregues ao destinatário.
*	
*	O preço dos cabos de rede utilizados nos roteadores da empresa pode chegar a ser muito caro, e a empresa precisa cortar gastos. Pensando nisso a empresa decidiu fazer algumas alterações na infra-estrutura de redes.
*	
*	Bruno deve modificar a infra-estrutura da rede da empresa de forma com que todos os roteadores consigam transmitir dados entre si e exista somente uma rota entre cada par de roteadores, economizando o máximo possível de cabos de internet.
*	
*	A sua tarefa é descobrir qual será o custo total com cabos que a empresa terá após as modificações feitas por Bruno. A figura abaixo mostra (a) a infraestrutura de redes atual; e (b) a infraestrutura de redes após as modificação feitas.
*	
*	
*	
*	Entrada
*	A primeira linha é composta por dois inteiros R (3 ≤ R ≤ 60) e C (R ≤ C ≤ 200) representado respectivamente a quantidade de roteadores e a quantidade de cabos de internet utilizados atualmente.
*	
*	Seguem C linhas, cada uma contendo três inteiros V (1 ≤ V ≤ R), W (1 ≤ W ≤ R) e P (1 ≤ P ≤ 10000), sendo V e W um par de roteadores que estão conectados por um cabo de internet e P o preço do cabo de internet utilizado.
*	
*	Saída
*	Seu programa deve imprimir um único valor inteiro que representa o custo total que a empresa gastará com cabos após as modificações.
*	
*	Exemplo de Entrada	Exemplo de Saída
*	7 12
*	1 3 6
*	1 4 9
*	2 3 17
*	2 5 32
*	2 7 27
*	3 4 11
*	3 5 4
*	4 5 3
*	4 6 19
*	5 6 13
*	5 7 15
*	6 7 5
*	
*	48
*/