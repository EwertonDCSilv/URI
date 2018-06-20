#include <stdio.h>
#include <stdlib.h>
 
int main() {
	
    int i =0,j=0;
	while(1){
		if(scanf("%i %i",&i,&j) !=2)
			break;
		
		printf("PROD = %i\n",(i*j));
    }
    return 0;
}

