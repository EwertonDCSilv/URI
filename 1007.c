#include <stdio.h>
#include <stdlib.h>
 
int main() {
	
    int i =0,j=0,k=0,l=0;
	int a =0;
	int b=0;
	int s=0;
	while(1){
		if(scanf("%i %i %i %i",&i,&j,&k,&l) !=4)
			break;
		
		a = (i*j);
		b = (k*l);
		s = a - b;
		printf("DIFERENCA = %i\n",s);
		
    }
    return 0;
}