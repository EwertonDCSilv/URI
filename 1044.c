#include <stdio.h>
#include <math.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
  
int main() {
   
	int a=0,b=0;
	
	while(1){
		
		
		if(scanf("%i %i",&a,&b) !=2)
				break;	
		if(a > b && a%b == 0)
			printf("Sao Multiplos\n");
		else if(a < b && b%a == 0)
			printf("Sao Multiplos\n");
		else 
			printf("Nao sao Multiplos\n");
	}
    return 0;
}