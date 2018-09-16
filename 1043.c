#include <stdio.h>

int main() {
   
	double a=0.0,b=0.0,c=0.0;
	
	while(1){
		
		
		if(scanf("%lf %lf %lf",&a,&b,&c) !=3)
				break;	
		
		if(a >= b + c)
			printf("Area = %0.1lf\n",(((a+b)/2)*(c)));
		else 
			printf("Perimetro = %0.1lf\n",a+b+c);
	}
    return 0;
}