#include <stdio.h>
#include <math.h>
  
int main() {
    
	int a=0;
	double b=0.0;
	double vet[5] = {4.00,4.50,5.00,2.00,1.50};

	while(1){
		
		if(scanf("%i %lf",&a,&b) !=2)
			break;	
	
		printf("Total: R$ %0.2lf\n",(vet[a-1]*b));
		
	}
    return 0;
}