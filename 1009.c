#include <stdio.h>
#include <stdlib.h>
 
int main() {
	
    double i =0.0,j=0.0,s=0.0;
	char n[100];

	while(1){
		if(scanf("%s %lf %lf",&n,&i,&j) !=3)
			break;
			
		s = j*0.15;
		
		printf("TOTAL = R$ %0.2lf\n",(i+s));
		
    }
    return 0;
}