#include <stdio.h>
#include <math.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
  
int main() {
   
	int a=0,b=0;
	int i=0,j=0;
	int vet[3];
	
	while(1){
		
		for(i=0;i<3;i++)
			if(scanf("%i",&vet[i]) !=1)
				break;	
		
		qsort(vet, 3, sizeof(int), cmpfunc);

		for(i=0;i<3;i++){
			if(i ==2)
				printf("%i\n\n",vet[i]);
			else
				printf("%i\n",vet[i]);
		}
		
		for(i=0;i<3;i++){
			printf("%i\n",vet[abs(j-i)]);
		}
	}
    return 0;
}