#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999999

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

void AllPaths(int s, int d, GRAFO * Grafo);
int R(int u, int d,int *path, int path_index, GRAFO * Grafo);
int AllPathsUtil(int u, int d,int *path, int path_index, GRAFO * Grafo);

int dijkstra(int **G,int **cost, int n){
		
	int startnode = 0,i = 0,j=0;
	int l = n +2;
	int count = 0,mindistance = 0, nextnode=0;
	/*int *distance;
	int *pred;
	int *visited;
	
	int count=0,mindistance=0,nextnode = 0,
	
	distance = (int*)malloc(sizeof(int)*l);
	pred = (int*)malloc(sizeof(int)*l);
	visited = (int*)malloc(sizeof(int)*l);*/
	
    int distance[l],pred[l];
    int visited[l];
	
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(G[i][j]==0){
                cost[i][j]=INFINITY;
            }else{
                cost[i][j]=G[i][j];
			}
		}
		//distance[i] = 0;
		pred[i] =0;		
		visited[i] = 0;		
	}	

    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
	
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
  
    while(count<n-1){
 
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++){
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
		}
           
        //check if a better path exists through nextnode            
        visited[nextnode]=1;
		
		for(i=0;i<n;i++){
			if(!visited[i]){
				if(mindistance+cost[nextnode][i]<distance[i]){
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
			
        count++;
    }
	
	int resposta;
	resposta = distance[n-1];
	if(resposta >= INFINITY){
		resposta =-1;
		printf("%d\n", resposta);
	}else{
		printf("%d\n", resposta);
	}
	return 0 ;
}


int verifRelacao(int v1,int v2,GRAFO *Grafo){
	int auxPeso = 0, i =0,j=0;
	PonteiroPraCelula Aux,Aux2;
	
	Aux = Grafo->VetLista[v1].Primeiro->Prox;//Apontador para o proximo
	 
	while(Aux != NULL){
		if(Aux->id_vizinho == v2){
			return Aux->peso;
		}	
		Aux = Aux->Prox;
	}
	return -1;
}

int comprime(GRAFO *Grafo, GRAFO *auxG, int n){
	
	int auxPeso = 0, i =0,j=0, r=0;
	PonteiroPraCelula Aux,Aux2;
	int **matrix;
	int **dd;
	
	matrix = (int**)malloc(sizeof(int*)*n+2);
	dd = (int**)malloc(sizeof(int*)*n+2);
	for(i=0;i<n;i++){
		matrix[i] = (int*)malloc(sizeof(int)*n+2);
		dd[i] = (int*)malloc(sizeof(int)*n+2);
	}
	
	for(i=0;i<Grafo->num_nos;i++){
		for(j=0;j<Grafo->num_nos;j++){
			matrix[i][j] = INFINITY;
		}
	}
	
	for(i=0;i<Grafo->num_nos;i++){
		Aux = Grafo->VetLista[i].Primeiro->Prox;//Apontador para o proximo
		
		Grafo->VetLista[i].vistiado = 1;//Define que o vertice foi visitado
		if(Grafo->VetLista[i].vistiado != -81 ){
			while(Aux != NULL){
				
				if(Grafo->VetLista[Aux->id_vizinho].vistiado != -881 ){
					
					Grafo->VetLista[Aux->id_vizinho].vistiado = 1;		
					Aux2 = Grafo->VetLista[Aux->id_vizinho].Primeiro->Prox;//Aponta para o vizinho do vizinho
				
					while(Aux2 != NULL){
						if(i != Aux2->id_vizinho && (Aux->peso + Aux2->peso)  !=0){	
							auxPeso = Aux->peso + Aux2->peso;
							//printf("Relacao %i\t%i\t%i\n",i+1,Aux2->id_vizinho +1 ,auxPeso);
						
							if(verifRelacao(i,Aux2->id_vizinho,auxG) == -1){
								InsereAresta(i,Aux2->id_vizinho,auxPeso,auxG);
								InsereAresta(Aux2->id_vizinho,i,auxPeso,auxG);
								matrix[i][Aux2->id_vizinho] = auxPeso;
								matrix[Aux2->id_vizinho][i] = auxPeso;
							}else{
								if(r < auxPeso){
									Aux->peso = r;
									Aux2->peso = r;
									matrix[i][Aux2->id_vizinho] = r;
								}
							}
						}
						Aux2 = Aux2->Prox;
					}
				}
				Aux = Aux->Prox;
			}
		}
	}
	LiberaGrafo(auxG);
	dijkstra(matrix,dd,n);

	return 0;
}

int main (int argc, char* argv[]){

	int L=0,N=0,M=0;
	int i=0,id=0;
	int resp = 0;
	int id_1=0,id_2=0,peso=0;
	GRAFO Grafo;
	GRAFO auxG;
	PonteiroPraCelula Aux;
	
	while(1){
		if((scanf("%i %i",&N,&M)) != 2)//Verifica se a entrada foram recebidos com sucesso
			break;
		
		CriaGrafo(N,&Grafo);//Cria a estrutura do tipo grafo
		CriaGrafo(N,&auxG);//Cria a estrutura do tipo grafo
			
		for(i=0;i<M;i++){
			
			//Recebe a relacao
			if(scanf(" %i %i %i",&id_1,&id_2,&peso) !=3)
				break;
			
			//printf("ID1: %i\tID2: %i\tPeso: %i\n\n",id_1,id_2,peso);
						
			InsereAresta(id_1-1,id_2-1,peso,&Grafo);//Cria a relacao de ida  0 a N-1
			InsereAresta(id_2-1,id_1-1,peso,&Grafo);//Cria a relacao de volta
		}
	
		//AllPaths(0,3,&Grafo);
		comprime(&Grafo,&auxG,N);
		
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
void AllPaths(int s, int d, GRAFO * Grafo){
	
    int *path;
	int N = 0, i=0, path_index = 0;
	
	N = Grafo->num_nos;
	path = (int*) calloc (N,sizeof(int));

    AllPathsUtil(s, d, path,path_index,Grafo);	
	free(path);
}
 
int AllPathsUtil(int u, int d,int *path, int path_index, GRAFO * Grafo){
	int i = 0,soma=0;
	PonteiroPraCelula Aux;
	
	Grafo->VetLista[u].vistiado = 1;

    path[path_index] = u;
    path_index++;
   
    if (u == d){
        for (i = 0; i< path_index; i++){
			printf("%i ",path[i]+1);
			//soma = soma + Grafo->VetLista[i];
		}
		printf("\n\n");
		//printf("\nSoma e de %i\n\n",soma);
    }else{
		for (i =0; i != Grafo->num_nos; ++i){
			if(Grafo->VetLista[i].vistiado != 1){
				Grafo->VetLista[i].vistiado = 1;
				path_index = AllPathsUtil(i, d, path, path_index,Grafo);
			}
		}
	}
	
    path_index--;
    Grafo->VetLista[u].vistiado = 0;
	
	return path_index;
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
