#include <stdio.h>
#include <stdlib.h>
 
#define PI 3.14159
 
int main() {
	
    int i =0,j=0;
	while(1){
		if(scanf("%i %i",&i,&j) !=2)
			break;
		
		printf("SOMA = %i\n",(i+j));
    }
    return 0;
}

