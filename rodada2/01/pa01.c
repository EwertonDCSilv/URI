#include <stdio.h>
#include <ctype.h>

void danca(char texto[]){
	int len =0,mod= 0,i= 0;
	int cont = 0;

	while(texto[cont]!='\0'){
		cont++;
	}
	
	for (i=0;i < (cont-1); i++){
		if (texto[i] != ' '){
			if (mod%2 ==0){
				texto[i]= toupper(texto[i]);
				mod= 1;
			}
			else if (mod%2 !=0){
				texto[i]= tolower(texto[i]);
				mod= 0;
			}
		}
	}
	for (i=0;i < (cont-1); i++){
		printf("%c",texto[i]);
	}
}

void main (){
	char texto[51];

    while(1){
		if(fgets(texto, 51, stdin) != NULL){
			danca(texto);
		}else{
			break;
		}
		printf("\n",texto);
    }
}


/*
*	URI Online Judge | 1234
*	Sentença Dançante
*	Por TopCoder*  EUA
*	
*	Timelimit: 1
*	Uma sentença é chamada de dançante se sua primeira letra for maiúscula e cada letra subsequente for o oposto da letra anterior. Espaços devem ser ignorados ao determinar o case (minúsculo/maiúsculo) de uma letra. Por exemplo, "A b Cd" é uma sentença dançante porque a primeira letra ('A') é maiúscula, a próxima letra ('b') é minúscula, a próxima letra ('C') é maiúscula, e a próxima letra ('d') é minúscula.
*	
*	Entrada
*	A entrada contém vários casos de teste. Cada caso de teste é composto por uma linha que contém uma sentença, que é uma string que contém entre 1 e 50 caracteres ('A'-'Z','a'-'z' ou espaço ' '), inclusive, ou no mínimo uma letra ('A'-'Z','a'-'z').
*	
*	Saída
*	Transforme a sentença de entrada em uma sentença dançante (conforme o exemplo abaixo) trocando as letras para minúscula ou maiúscula onde for necessário. Todos os espaços da sentença original deverão ser preservados, ou seja, " sentence " deverá ser convertido para " SeNtEnCe ".
*	
*	Exemplo de Entrada	Exemplo de Saída
*	This is a dancing sentence
*	This   is         a  dancing   sentence  
*	aaaaaaaaaaa
*	z
*	
*	ThIs Is A dAnCiNg SeNtEnCe
*	ThIs   Is         A  dAnCiNg   SeNtEnCe  
*	AaAaAaAaAaA
*	Z
*/