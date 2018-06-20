#include <stdio.h>
#include <stdlib.h>
 
int main() {
    
	int id1=0,id2=0,c1,c2;
	double val1=0.0,val2=0.0;

	while(1){
		if(scanf("%i %i %lf",&id1,&c1,&val1) !=3)
			break;
		
		if(scanf("%i %i %lf",&id2,&c2,&val2) !=3)
			break;
		
		
		printf("VALOR A PAGAR: R$ %0.2lf\n",((c1*val1)+(c2*val2)));
		
    }
    return 0;
}