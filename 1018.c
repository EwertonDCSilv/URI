#include <stdio.h>
#include <stdlib.h>
  
int main() {
    
	int i=0,a=0,b=0,j=0;
	int cont = 0;
	int vet[7];
	
	while(1){
		
		if(scanf("%i",&i) !=1)
			break;
		
		printf("%i\n",i);
		
		for (j=0;j<7;j++){
			vet[j] = 0;
		}
		
		if(i >= 100){
			vet[0] = i/100;
			i = i%100;
		}
		
		printf("%i nota(s) de R$ 100,00\n",vet[0]);
		
		if(i >= 50){
			vet[1] = i/50;
			i = i%50;
		}
		
		printf("%i nota(s) de R$ 50,00\n",vet[1]);
		
		if(i >= 20){
			vet[2] = i/20;
			i = i%20;
		}
		
		printf("%i nota(s) de R$ 20,00\n",vet[2]);
		
		if(i >= 10){
			vet[3] = i/10;
			i = i%10;
		}
		
		printf("%i nota(s) de R$ 10,00\n",vet[3]);
		
		if(i >= 5){
			vet[4] = i/5;
			i = i%5;
		}
		
		printf("%i nota(s) de R$ 5,00\n",vet[4]);
		
		if(i >= 2){
			vet[5] = i/2;
			i = i%2;
		}
		
		printf("%i nota(s) de R$ 2,00\n",vet[5]);
		
		if(i >= 1){
			vet[6] = i/1;
			i = i%1;
		}
		
		printf("%i nota(s) de R$ 1,00\n",vet[6]);

	}	
	
    return 0;
}