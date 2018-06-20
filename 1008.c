#include <stdio.h>
#include <stdlib.h>
 
int main() {
	
    int i =0,j=0;
	float k=0;

	while(1){
		if(scanf("%i %i %f",&i,&j,&k) !=3)
			break;
		
		printf("NUMBER = %i\n",i);
		printf("SALARY = U$ %0.2f\n",(j*k));
		
    }
    return 0;
}