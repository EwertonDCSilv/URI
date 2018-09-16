#include <stdio.h>
#include <stdlib.h>

void sort(int vet[], int m){//Metodo de ordenamento Descrence bouble sort
	int i = 0, j =0;
	int max = 0;
	int flag = 0;
	for(i=0;i<m;i++){
		max = vet[i];//Considera este sendo o possivel maior numero
		for (j=0;j<m;j++){
			if (vet[j]< max){
				vet[i] = vet[j];
				vet[j] = max;
				max = vet[i];
			}
		}
	}
}

int diferenca(int vet[], int flag[],int m){	//Analisa a diferenca entre os vetores
	int i=0,j=0,contador=0;					//Verifica se os mesmo indices tem os mesmo valores		
	for (i=0; i<m; i++)						//Caso nao, incrementa 1 no contador
		if(flag[i] == vet[i])
			contador++;
	return contador;
}

int main(int argc, char* argv[]){

	int n = 0,m = 0, i = 0,j = 0;
	int *resultados;
	int *v;
	int *flag;
	
	scanf("%i",&n);//Recebendo o numero de casos a serem executado	
	resultados = (int*) malloc(n*sizeof(int));//Alocando memoria para o vetor de resultados

	for(i=0;i<n;i++){
		scanf("%i",&m);	//Recebendo o numero de alunos na fila
		v = (int*) malloc (m*sizeof(int));//Alocando memoria dinamicamente para os vetores
		flag = (int*) malloc (m*sizeof(int));
		
		for (j=0;j<m;j++){
			v[j] = 0;
			flag[j] = 0;
			scanf("%d",&v[j]);	//Recebendo os valores 
			flag[j]= v[j];//Atribuindo valor a um vetor de flag
		}		
		
		sort(v,m);//Ordenando vetor
		resultados[i] = diferenca(v,flag,m);//Analisando a diferenca entre os veotres 
		m=0;
		free(v);
		free(flag);		
	}
	
	for(i=0;i<n;i++){//Imprimindo o resultado de todos os casos
		printf("%i\n",resultados[i]);
	}
	
	free(resultados);//Desalocando memoria do vetor
	return 0;
}

/*
*	URI Online Judge | 1548
*	Fila do Recreio
*	Por Cristhian Bonilha, UTFPR BR Brazil
*	
*	Timelimit: 1
*	
*	Na escola onde você estuda, a hora do recreio é a mais aguardada pela 
*	grande maioria dos alunos. Não só porque as vezes as aulas são cansativas,
*	mas sim porque a merenda servida é muito boa, preparada por um chefe italiano 
*	muito caprichoso.
*	
*	Quando bate o sinal para a hora do recreio, todos os alunos saem correndo da sua sala
*	para chegar o mais cedo possível na cantina, tanta é a vontade de comer.
*	Um de seus professores notou, porém, que havia ali uma oportunidade.
*	
*	Utilizando um sistema de recompensa, seu professor de matemática disse que a ordem 
*	da fila para se servir será dada não pela ordem de chegada, mas sim pela soma das 
*	notas obtidas em sala de aula. Assim, aqueles com maior nota poderão se servir antes 
*	daqueles que tem menor nota.
*	
*	Sua tarefa é simples: dada a ordem de chegada dos alunos na cantina, e 
*	as suas respectivas notas na matéria de matemática, reordene a fila de acordo 
*	com as notas de matemática, e diga quantos alunos não precisaram trocar de lugar 
*	nessa reordenação.
*	
*	Entrada
*	
*	A primeira linha contém um inteiro N, indicando o número de casos de teste a seguir.
*	
*	Cada caso de teste inicia com um inteiro M (1 ≤ M ≤ 1000), indicando o
*	número de alunos. Em seguida haverá M inteiros distintos Pi (1 ≤ Pi ≤ 1000), 
*	onde o i-ésimo inteiro indica a nota do i-ésimo aluno.
*	
*	Os inteiros acima são dados em ordem de chegada, ou seja, o primeiro 
*	inteiro diz respeito ao primeiro aluno a chegar na fila, o segundo inteiro diz
*	respeito ao segundo aluno, e assim sucessivamente.
*	
*	Saída
*	
*	Para cada caso de teste imprima uma linha, contendo um inteiro, 
*	indicando o número de alunos que não precisaram trocar de lugar mesmo 
*	após a fila ser reordenada.
*
*	Exemplo de Entrada	
*	
*		3
*		3
*		100 80 90
*		4
*		100 120 30 50
*		4
*		100 90 30 25
*	
*	Exemplo de Saída
*	
*		1
*		0
*		4
*
*/