#include <stdio.h>
#include <math.h>
  
int main() {
   
	double a=0.0,b=0.0;
	
	while(1){
		
		if(scanf("%lf %lf",&a,&b) !=2)
			break;	
	
		if(a > 0 && b > 0)
			printf("Q1\n");
		else if(a > 0 && b < 0)
			printf("Q4\n");
		else if(a < 0 && b > 0)
			printf("Q2\n");
		else if(a <	0 && b < 0)
			printf("Q3\n");
		else if(a ==0.0 && b== 0.0)
			printf("Origem\n");		
		else if(a == 0.0 && b != 0.0)
			printf("Eixo Y\n");		
		else if(b == 0.0 && a != 0.0)
			printf("Eixo X\n");		
	}
    return 0;
}