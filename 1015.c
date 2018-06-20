#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
int main() {
    
	double a1=0.0,a2=0.0;
	double b1=0.0,b2=0.0;
	double r=0.0;
	
	while(1){
		
		if(scanf("%lf %lf %lf %lf",&a1,&b1,&a2,&b2) !=4)
			break;
		
		r = sqrt(pow((a2-a1),2.0) + pow((b2-b1),2.0));
		
		printf("%0.4lf\n",r);
	}	
	
    return 0;
}