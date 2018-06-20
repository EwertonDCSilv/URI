#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
int main() {    
	int a=0;

	while(1){
		
		if(scanf("%i",&a) !=1)
			break;
			
		printf("%i minutos\n",a*2);
	}	
	
    return 0;
}