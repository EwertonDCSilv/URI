#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i=0,j=0,k=0,l=0;
	int N=-1,M=-1;
	int *vetA;
	int *vetB;
	int *vetC;
	int *vetD;
	
	while(1){
		scanf("%i",&N);
		if(N==0)
			break;

		vetA = calloc(N,sizeof(int));
		vetB = calloc(N,sizeof(int));
		
		for(i=0;i<N;i++){
			scanf("%i %i",&vetA[i],&vetB[i]);
			printf("i%i | %i\n",i,vetA[i],vetB[i]);
		}
		
		scanf("%i",&M);
		vetC = calloc(M,sizeof(int));
		vetD = calloc(M,sizeof(int));
			
		for(i=0;i<M;i++){
			scanf("%i %i",&vetC[i],&vetD[i]);
		}
		
		/*printf("Cidade# %i:\n",j+1);
		printf("Consumo medio: %0.2lf m3.",4);
		printf("\n");
		j++;*/
		
		N = -1;
	}
		
	return 0;
}