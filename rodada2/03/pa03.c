#include <stdio.h>
int tamanho (char vet[]){//Define COmprimento da string
	int i=0;
	while(vet[i]!='\0')
		i++;
	return i;
}

void limpaPeriod(int vet[],int n){//Inicializa o vetor de ocorrencias
	int i=0;
	for(i=0;i<n;i++)
		vet[i] = 0;
}

void analise_Text(int periodo[],char texto[],int len){//Define a ocorrencia de um caracter no texto
	int i=0,k=0;
	for (i=0;i<len;i++){//Analisa quais sao as letras do texto
		k =  texto[i];
		periodo[k]++;
	}
}

void main(){
    char texto[1100];
    int periodo[255];
	int mod1=0, mod0=0;
	int i=0,k=0,len=0;

    while (1){
		if(scanf("%s", &texto) != 1){
			break;
		}
		
		limpaPeriod(periodo,255);//Limpa o vetor de contagem de caracteres da Tabela ASCII
		len = tamanho(texto);//Define o tamanho to texto
		analise_Text(periodo,texto,len);//Define a ocorrencia de uma caracter na Tabela ASCII
		
		for(i=0;i<255;i++){//Analisa a ocorrencia das letras no texto na Tabela ASCII
			if (periodo[i] % 2 == 1)
				mod1++;
		}
		
		if (mod1 <= 1){
			printf("0\n");
			mod0=0;
			mod1=0;
			continue;
		}else{
			mod1 = mod1-1;
			printf("%i\n",mod1);
			mod0=0;
			mod1=0;
			continue;
		}
	}
}
/*
*	URI Online Judge | 2588
*	Jogo dos Palíndromos
*	Por Ricardo Martins, IFSULDEMINAS BR Brazil
*	
*	Timelimit: 1
*	Rener era um garoto que adorava palíndromos. Tanto que inventou um jogo com estes. Dada uma sequência de letras, quantas mais teriam que ser adicionadas, pelo menos, de modo que alguma permutação desta sequência formasse um palíndromo. Por exemplo, batata precisa adicionar um b no final, para virar o palíndromo batatab. Em outro exemplo, aabb, não precisa adicionar nenhuma letra, pois se faz o palíndromo abba ou baab. Em mais um exemplo, abc precisa de duas letras a mais, para formar um palíndromo, que pode ser abcba, acbca, bacab, bcacb, cabac ou cbabc. Escreva um programa que, dada uma sequência de letras, informe qual é o mínimo de letras que precisam ser adicionadas à sequência, para que haja, pelo menos, um anagrama que forme um palíndromo.
*	
*	Entrada
*	Haverá diversos casos de teste. Em cada caso, é mostrada uma sequência de, no máximo, 1000 letras. Os casos de teste terminam com fim de arquivo.
*	
*	Saída
*	Para cada caso de teste, imprima um valor inteiro, correspondente à quantidade mínima de letras a serem acrescentadas para que a sequência se torne um palíndromo, em uma de suas permutações.
*	
*	Exemplo de Entrada	Exemplo de Saída
*	batata
*	aabb
*	abc
*	
*	1
*	0
*	2
*/