#include <stdio.h>
#include <stdlib.h>
  
int main() {
    
	int i=0,a=0;
	
	while(1){
		
		if(scanf("%i",&i) !=1)
			break;
		
		if(i >= 365){
			a = i/365;
			i = i%365;
		}
		printf("%i ano(s)\n",a);
		
		if(i < 365 && i >= 30){
			a = i/30;
			i = i%30;
		}
		
		printf("%i mes(es)\n",a);
		printf("%i dia(s)\n",i);
	}	
	
    return 0;
}