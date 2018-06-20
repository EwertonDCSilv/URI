#include <stdio.h>
#include <stdlib.h>
 
int main() {
	
    float i =0.0,j=0.0;
	while(1){
		if(scanf("%f %f",&i,&j) !=2)
			break;
		
		printf("MEDIA = %0.5f\n",((i*3.5)+(j*7.5))/11);
		
    }
    return 0;
}