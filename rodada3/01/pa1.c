#include <stdlib.h>
#include <stdio.h>

long long int cont = 0;

int sort(int *vet, int N){
	int i=0,j=0,aux=0,a=0;
	
	while(i<N){
		if((vet[i]-1) != i){//Verifica se o valor esta invertido
		
			j = vet[i] -1;//Vefine o indice correto para o valor autal
			a = (vet[i] -1+i)*2-1;//Realiza o calculo de diferenca entre os indices invertidos
		
			if(a < 0)//Verifica se a diferenca e negativa
				a = a * -1;//torna a diferenca positiva
		
			cont = cont + a;//Soma a diferenca ao contador
			//Realiza a troca de indices desordenados
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
		}
		else if(vet[i] == i+1)
			i = i +1;
	}
	return cont;
}


int main(){
	int i=0,j=0,N=0;
	int *vet;
	while(1){//Define o ciclo
		cont =0;
		scanf("%i",&N);//Define a quatidade de numeros recebidos
		
		if(N==0)//Finaliza o programa se N for 0
			break;
		vet = (int*)calloc(N, sizeof(int));;//Define comprimento do vetor]
		
		for(i=0;i<N;i++)//Insere valores no vetoe
			scanf("%i",&vet[i]);
				
		cont = sort(vet,N);//Ordenando e contando a distancia de edicao
		
		//printf("Cont %lli \t",cont);
		
		if(cont%2 == 0)//Se for par Carlos Ganha
			printf("Carlos\n",cont);		
		else//Se for impar Marcelo Ganha
			printf("Marcelo\n",cont);		
		
		cont=0;
		free(vet);
	}
	return 0;
}
/*
*	URI Online Judge | 1088
*	Bolhas e Baldes
*	Por Cláudio L. Lucchesi  Brasil
*	
*	Timelimit: 3
*	Andrea, Carlos e Marcelo são muito amigos e passam todos os finais de semana à beira da piscina. Enquanto Andrea se bronzeia ao sol, os dois ficam jogando Bolhas. Andrea, uma cientista da computação muito esperta, já disse a eles que não entende por que passam tanto tempo jogando um jogo tão primário.
*	
*	Usando o computador portátil dela, os dois geram um inteiro aleatório N e uma seqüência de inteiros, também aleatória, que é uma permutação de 1, 2, . . . ,N.
*	
*	O jogo então começa, cada jogador faz um movimento, e a jogada passa para o outro jogador. Marcelo é sempre o primeiro a começar a jogar. Um movimento de um jogador consiste na escolha de um par de elementos consecutivos da seqüência que estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo, dada a seqüência 1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou de 4 e 2, mas não pode inverter as posições de 3 e 4, nem de 5 e 2. Continuando com o exemplo, se o jogador decide inverter as posições de 5 e 3 então a nova seqüência será 1, 3, 5, 4, 2.
*	
*	Mais cedo ou mais tarde, a seqüência ficará ordenada. Perde o jogador impossibilitado de fazer um movimento. Andrea, com algum desdém, sempre diz que seria mais simples jogar cara ou coroa, com o mesmo efeito. Sua missão, caso decida aceitá-la, é determinar quem ganha o jogo, dada a seqüência inicial.
*	
*	Entrada
*	A entrada contém vários casos de teste. Os dados de cada caso de teste estão numa única linha, e são inteiros separados por um espaço em branco. Cada linha contém um inteiroN (2 ≤ N ≤ 105), seguido da seqüência inicial P = (X1, X2, ...,XN) de N inteiros distintos dois a dois, onde1 ≤ Xi ≤ N para 1 ≤ i ≤ N.
*	
*	O final da entrada é indicado por uma linha que contém apenas o número zero.
*	
*	Saída
*	Para cada caso de teste da entrada seu programa deve imprimir uma única linha, com o nome do vencedor, igual a Carlos ou Marcelo., sem espaços em branco.
*	
*	Exemplo de Entrada	Exemplo de Saída
*	5 1 5 3 4 2
*	5 5 1 3 4 2
*	5 1 2 3 4 5
*	6 3 5 2 1 4 6
*	5 5 4 3 2 1
*	6 6 5 4 3 2 1
*	0
*	
*	Marcelo
*	Carlos
*	Carlos
*	Carlos
*	Carlos
*	Marcelo
*	
*	Maratona de Programação da SBC 2008.
*/