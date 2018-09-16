#include <stdlib.h>
#include <stdio.h>


int calcula(int *roleta, int *bolas, int N, int M){
	int i=0, e=0,cont=0,max=0;
	int ball = bolas[0];
	
	for(i=0;i<N;i++){
		max += bolas[i];
	}
	
	max = abs(max * ball) * (-1);

	for(i=0;i<N;i++){
		int next = roleta[(i + 1) % N];

		if ((roleta[i] + next) * (ball*(-1)) > max){
			max = (roleta[i] + next) *(ball*(-1));
		}
	}	

	return max;
}



int main(){
	int i=0,j=0,k=0,aux=9999999;
	int N=0,M=0,L;
	int menor = 0;
	
	while(1){//Define o ciclo
	
		scanf("%i",&N);//Define a quatidade de numeros Emojis
		scanf("%i",&M);//Define a quatidade de numeros Strings
		
		if(N==0 && M==0)//Caso ambos seja verdadeiro finaliza o programa
			break;
		L = N+1;
		
		int vet[L];
		//		int menor[M];
		int matriz[N][M];
		int soma[N][M];
		int bolas[M];

		for(i=0;i<N;i++){
			scanf("%i",&vet[i]);
			if(i==0)
				vet[N] = vet[i];			
		}

		for(i=0;i<M;i++)
			scanf("%i",&bolas[i]);
		
		menor = calcula(vet,bolas,N,M);
		printf("%i\n",menor);
		
		menor= 0;
	}
	
	return 0;
}