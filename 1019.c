#include <stdio.h>
#include <stdlib.h>
  
int main() {
    
	int i=0,a=0;
	
	while(1){
		
		if(scanf("%i",&i) !=1)
			break;
		
		if(i >= 3600){
			a = i/3600;
			i = i%3600;
		}
		printf("%i:",a);
		
		if(i < 3600 && i >= 60 ){
			a = i/60;
			i = i%60;
		}
		
		printf("%i:",a);
		printf("%i\n",i);
	}	
	
    return 0;
}