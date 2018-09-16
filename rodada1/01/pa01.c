#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

	int n = 0,r= 0, i = 0,j = 0,l=0,k=0,u=0;
	int vale = 0;
	
	while(1){
		scanf("%i",&n);//Recebendo o numero de casos a serem executado	
		if(n==0){
			break;
		}
		j = n+2;
		int vet[j];
		
		for (i=0;i<n;i++){
			scanf("%i",&vet[i]);
			if(i == 0)
				vet[n] = vet[i];
			if(i == 1)
				vet[n+1] = vet[i];
		}		
			
		for (i=1;i<j-1;i++){			
			//printf("%i\t",vet[i]);
			l = i-1;
			k = i+1;
			//	printf("valor de i%i \ti+1 %i\t-1 %i\n",vet[i],vet[i+1],vet[i-1]);
			if( vet[i] < vet[l] && vet[i] < vet[k] )
				vale ++;
			if(vet[i] > vet[l] && vet[i] > vet[k] )
				vale ++;
		}	
		
		printf("%i\n",vale);
		vale=0;
	}
	
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