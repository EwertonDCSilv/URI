#include <stdio.h>
  
int main() {
    
	int a=0,b=0,c=0,d=0;

	while(1){
		
		if(scanf("%i %i %i %i",&a,&b,&c,&d) !=4)
			break;
	
		if(b > c && b > a && (c+d) > (a+b) && c >0 && d > 0 && a %2 ==0 )
			printf("Valores aceitos\n");
		else
			printf("Valores nao aceitos\n");		
	}
    return 0;
}