#include <stdio.h>
#include <math.h>
  
int main() {
    
	double a=0.0,b=0.0,c=0.0,delta=0.0;
	double x1=0.0,x2=0.0;

	while(1){
		
		if(scanf("%lf %lf %lf",&a,&b,&c) !=3)
			break;
	
		delta = (b*b)+ (-4*a*c);

		if(delta > 0 && a != 0){
			x1 = (((-1.0*b)+(sqrt(delta)))/(2*a)); 
			x2 = (((-1.0*b)+(-1.0*sqrt(delta)))/(2*a));
		
			printf("R1 = %0.5lf\n",x1);
			printf("R2 = %0.5lf\n",x2);
			
		}else{
			printf("Impossivel calcular\n");		
		}	
	}
    return 0;
}