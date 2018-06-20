#include <stdio.h>
#include <stdlib.h>
  
int main() {
    
	int i=0;
	int r=0;
	int vet[3];

	while(1){
		
		if(scanf("%i %i %i",&vet[0],&vet[1],&vet[2]) !=3)
			break;
		
		r = ((vet[0] + vet[1] + abs(vet[0] -vet[1]))/2);
		
		if (r == vet[0])
			r = r = ((vet[0] + vet[2] + abs(vet[0] -vet[2]))/2);
		else
			r = ((vet[2] + vet[1] + abs(vet[2] -vet[1]))/2);
	
		
		printf("%i eh o maior\n",r);
	}	
	
    return 0;
}