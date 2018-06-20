#include <stdio.h>
#include <stdlib.h>
 
int main() {
	
    float i =0.0,j=0.0,k=0.0;
	while(1){
		if(scanf("%f %f %f",&i,&j,&k) !=3)
			break;
		
		printf("MEDIA = %0.1f\n",((i*2.0)+(j*3.0)+(k*5.0))/10);
		
    }
    return 0;
}