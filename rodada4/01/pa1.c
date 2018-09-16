#include <stdio.h>
#include <stdlib.h>

int saida[26];

typedef struct Celula* PonteiroPraCelula ;
struct Celula{
	int id_vizinho;
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
void InsereLista(int id_vizinho, LISTA *lista);

void CriaGrafo(int N,GRAFO *Grafo);
void InsereAresta(int V1, int V2, GRAFO *Grafo);
void LiberaGrafo(GRAFO *Grafo);

void DFS(int v,GRAFO *Grafo);
void Conexao(GRAFO *Grafo);

int main (int argc, char* argv[]){

	int L=0,N=0,M=0;
	int i=0,id=0,idade=0;
	char id_1,id_2;
	int id_u,id_d;
	int p = 0;
	GRAFO Grafo;
	
	scanf("%i",&L);//Numero de rodadas
	
	for(p=0; p<L; p++){
		
		if((scanf("%d %d\n",&N,&M)) != 2)//Verifica se a entrada foram recebidos com sucesso
			printf("Erro ao ler o numero de Nos e relacoes");
	
		CriaGrafo(N,&Grafo);//Cria a estrutura do tipo grafo
			
		if(M !=0){
			for(i=0;i<M;i++){
				
				//Recebe a relacao
				scanf("%c",&id_1);
				scanf(" %c\n",&id_2);
										
				id_u = ((int)toupper(id_1)) - 65;//Converte em um numero de 0 a 25	
				id_d = ((int)toupper(id_2)) - 65;//Converte em um numero de 0 a 25	
						
				InsereAresta(id_u,id_d,&Grafo);//Cria a relacao de ida 
				InsereAresta(id_d,id_u,&Grafo);//Cria a relacao de volta
			}
		}
			
		printf("Case #%i:\n",p+1);//Imprime o indice do caso
		Conexao(&Grafo);//Analisa os componetes conexos'
		LiberaGrafo(&Grafo);//Desalocando a Memoria usada pelo Grafo
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
void InsereLista(int id_vizinho, LISTA *lista){//Complexidade O = (1)
	lista->Ultimo->Prox = (PonteiroPraCelula)malloc(sizeof(Celula));//Aloca memoria para um ponteira para celula
	lista->Ultimo = lista->Ultimo->Prox;
	lista->Ultimo->id_vizinho = id_vizinho;//Insere o id da vertice adjacente
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
void InsereAresta(int V1, int V2, GRAFO *Grafo){//Complexidade O = (1)
	Grafo->VetLista[V1].vistiado = 0;//Incializa a propriedade como 0
	InsereLista(V2, &Grafo->VetLista[V1]);//Insere vizinho na lista de Adjacencia
}

//________ Funcao de conectividade do grafo ________//
void Conexao(GRAFO *Grafo){
	int v=0;
	int cont=0,i=0;
	
	for (v=0; v< Grafo->num_nos; v++)//Define todos como nao vizitados
		Grafo->VetLista[v].vistiado = 0;
	
	for(i=0;i<26;i++)//Percorre o vetor de saida
		saida[i] = -1;//Inicializa o vetor 
	
    for (v=0; v< Grafo->num_nos; v++){//Executada para todo os nos
        if (Grafo->VetLista[v].vistiado == 0){//Executado apenas para componeste que nao foram visitados
            DFS(v,Grafo);//Chama DFS para o vertice			
			for(i=0;i<26;i++){//Percorre o vetor de saida
				if(saida[i] !=-1)//Verifica se o elemento percente esta conexo
					printf("%c,",i+97);//Printa o indice mais + 97 para caracteres min ASCII
				saida[i] = -1;//Inicializa o vetor 
			}
			printf("\n");
			cont++;//Incrementa o contador de componetes
        }
    }	
	printf("%i connected components\n\n",cont);//Printa o numero de componetes conexos
}

//________ Funcao de busca no grafo ________//
void DFS(int id,GRAFO *Grafo){
	
	PonteiroPraCelula Aux;
	Aux = Grafo->VetLista[id].Primeiro->Prox;//Apontador para o proximo
	
	Grafo->VetLista[id].vistiado = 1;//Define que o vertice foi visitado
	saida[id] = 1;//Define o vetor de flag saida como 1
 
	while(Aux != NULL){//Executa o loop ate chegar ao ultimo da lista ou enquanto M maior que 0
	
		if(Grafo->VetLista[Aux->id_vizinho].vistiado != 1 ){//Chama a funcao de DFS caso o vizinho nao tenha sido vizitado
			DFS(Aux->id_vizinho,Grafo);
		}
		Aux = Aux->Prox;//Recebe o apontador para o proximo da lista
	}
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
*	URI Online Judge | 1082
*	Componentes Conexos
*	Por Neilor Tonin, URI  Brasil
*	
*	Timelimit: 1
*	Com base nestas três definições:
*	
*	Grafo conexo: Um grafo G(V,A) é conexo se para cada par de nodos u e v existe um caminho entre u e v. Um grafo com apenas um componente é um grafo conexo.
*	
*	Grafo desconexo: Um grafo G(V,A) é desconexo se ele for formado por 2 ou mais componentes conexos.
*	
*	Componente conexo: Componentes conexos de um grafo são os subgrafos conexos deste grafo.
*	
*	O grafo a seguir possui 3 componentes conexos. O primeiro é formado pelos nodos a,b,c. O segundo é formado unicamente pelo nodo d e o terceiro componente é formado pelos nodos e,f.
*	
*	
*	
*	Com base nestes conceitos, onde cada entrada fornecida que tem a identificação de cada um dos vértices, arestas e as ligações entre os vértices através destas arestas,  liste cada um dos componentes conexos que existem no grafo, segundo a entrada fornecida.
*	
*	Entrada
*	A primeira linha do arquivo de entrada contém um valor inteiro N que representa a quantidade de casos de teste que vem a seguir. Cada caso de teste contém dois valores V e E que são, respectivamente, a quantidade de Vértices e arestas (Edges) do grafo. Seguem E linhas na sequência, cada uma delas representando uma das arestas que ligam tais vértices. Cada vértice é representado por uma letra minúscula do alfabeto ('a'-'z'), ou seja, cada grafo pode ter no máximo 26 vértices. Cada grafo tem no mínimo 1 componente conexo.
*	
*	Obs: Os vértices de cada caso de teste sempre iniciam no 'a'. Isso significa que um caso de teste que tem 3 vértices, tem obrigatoriamente os vértices 'a', 'b' e 'c'.
*	
*	Saída
*	Para cada caso de teste da entrada, deve ser apresentada uma mensagem Case #n:, onde n indica o número do caso de teste (conforme exemplo abaixo). Segue a listagem dos vértices de cada segmento, um segmento por linha, separados por vírgula (inclusive com uma virgula no final da linha). Finalizando o caso de teste, deve ser apresentada uma mensagem indicando a quantidade de componentes conexos do grafo (em inglês). Todo caso de teste deve ter uma linha em branco no final, inclusive o último caso de teste.
*	
*	Obs: os nodos devem sempre ser apresentados em ordem crescente e se há caminho de a até b significa que há caminho de b até a.
*	
*	Exemplo de Entrada	Exemplo de Saída
*	3
*	3 1
*	a c
*	10 10
*	a b
*	a c
*	a g
*	b c
*	c g
*	e d
*	d f
*	h i
*	i j
*	j h
*	6 4
*	a b
*	b c
*	c a
*	e f
*	
*	Case #1:
*	a,c,
*	b,
*	2 connected components
*	
*	Case #2:
*	a,b,c,g,
*	d,e,f,
*	h,i,j,
*	3 connected components
*	
*	Case #3:
*	a,b,c,
*	d,
*	e,f,
*	3 connected components
*
*/