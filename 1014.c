#include <stdio.h>
#include <stdlib.h>
  
int main() {
    
	double i=0.0;
	double j=0.0;
	
	while(1){
		
		if(scanf("%lf %lf",&i,&j) !=2)
			break;
		
		printf("%0.3lf km/l\n",(i/j));
	}	
	
    return 0;
}