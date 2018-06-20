#include <stdio.h>
#include <stdlib.h>
 
#define PI 3.14159
 
int main() {
	
    double i =0.0;
	while(1){
		if(scanf("%lf",&i) !=1)
			break;
		printf("A=%0.4lf\n",(PI*(i*i)));
    }
    return 0;
}