#include <stdio.h>
#include <stdlib.h>

#define pi 3.14159
 

int main() {
    
	double i=0.0;
	double val=0.0;

	while(1){
		if(scanf("%lf",&i) !=1)
			break;
		
		val = (4.0/3) * pi * (i*i*i);
			
		printf("VOLUME = %0.3lf\n",val);
		
    }
    return 0;
}