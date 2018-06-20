#include <stdio.h>
#include <stdlib.h>

#define pi 3.14159
 

int main() {
    
	double i=0.0;
	double a=0.0,b=0.0,c=0.0, r=0.0;

	while(1){
		if(scanf("%lf %lf %lf",&a,&b,&c) !=3)
			break;
			
		r = (a*c)/2;
		printf("TRIANGULO: %0.3lf\n",r);
		
		r = (pi*(c*c));
		printf("CIRCULO: %0.3lf\n",r);
		
		r = (((a+b)/2)*c);
		printf("TRAPEZIO: %0.3lf\n",r);
		
		r = (b*b);
		printf("QUADRADO: %0.3lf\n",r);
		
		r = (a*b);
		printf("RETANGULO: %0.3lf\n",r);
	}	
	
    return 0;
}