#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
int main() {
    
	double a=0,b=0;
	int i = 0,j=0;
	int vet[7];
	double vetD[5];
	double val=0.0;
	
	while(1){
		
		if(scanf("%lf",&val) !=1)
			break;
		
		i = (int) val;
		b = val - i;
		
		printf("NOTAS:\n");
		
		for (j=0;j<7;j++)
			vet[j] = 0;
		
		for (j=0;j<5;j++)
			vetD[j] = 0.0;
		
		if(i >= 100){
			vet[0] = i/100;
			i = i%100;
		}
		printf("%i nota(s) de R$ 100.00\n",vet[0]);
		
		if(i >= 50){
			vet[1] = i/50;
			i = i%50;
		}
		printf("%i nota(s) de R$ 50.00\n",vet[1]);
		
		if(i >= 20){
			vet[2] = i/20;
			i = i%20;
		}
		printf("%i nota(s) de R$ 20.00\n",vet[2]);
		
		if(i >= 10){
			vet[3] = i/10;
			i = i%10;
		}
		printf("%i nota(s) de R$ 10.00\n",vet[3]);
		
		if(i >= 5){
			vet[4] = i/5;
			i = i%5;
		}
		printf("%i nota(s) de R$ 5.00\n",vet[4]);
		
		if(i >= 2){
			vet[5] = i/2;
			i = i%2;
		}
		
		printf("%i nota(s) de R$ 2.00\n",vet[5]);
		printf("MOEDAS:\n");
		
		if(i >= 1){
			vet[6] = i/1;
		}
		printf("%i moeda(s) de R$ 1.00\n",vet[6]);
		
		if(b< 1.0 && b >= 0.50){
			vetD[0] = floor(b/0.50);
			b = b - 0.50;
		}
		printf("%.0lf moeda(s) de R$ 0.50\n",vetD[0]);
		
		if(b < 0.50 && b >= 0.25){
			vetD[1] = floor(b/0.25);
			b = b - 0.25;
		}
		printf("%.0lf moeda(s) de R$ 0.25\n",vetD[1]);
		
		if(b< 0.25 && b>= 0.10){
			vetD[2] = floor(b/0.10);
		
			b = b - ((int)vetD[2] * 0.10);
		}
		printf("%.0lf moeda(s) de R$ 0.10\n",vetD[2]);
		
		if(b< 0.10 && b>= 0.05){
			vetD[3] = b/0.05;	
			b = b - 0.05;
		}
		printf("%.0lf moeda(s) de R$ 0.05\n",vetD[3]);		

		if(b< 0.05){
			vetD[4] = (b/0.01);
		}
		printf("%.0lf moeda(s) de R$ 0.01\n",vetD[4]);
	
	}	
	
    return 0;
}