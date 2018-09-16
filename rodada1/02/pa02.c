#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	int i =0,l = 0,c = 0,n=0,pagina=0,cont=0,r=0;
	char ch[100000];
	
	while(scanf("%d %d %d",&n,&l,&c) == 3){
		int  len[n];//Define o vetor a cada interação do laco
		for(i=0;i<n;i++){//Lendo as palavra por palavra
			scanf("%s",&ch);	
			len[i] = strlen(ch)+1;//atribuindo ao vetor o comprimento de cada string
		}
		cont = 0;//Sempre zera o contador a cada interação
		i=0;
		while(i < n){
			//Incrementa o comprimento das palavras enquanto meno que o max caracter
			if( cont+ len[i] <=c+1){
				cont = cont+ len[i];
			}
			//Caso o contador seja maior que o max caracter incrementa um no numero de pagina 
			else{
                cont = len[i];//faz o caracter de indice i o valor do contador 
                pagina++;//Incrementa um no numero de paginas
            }
			i++;
		}
		//faz o piso do numero de paginas pelo max de caracteres
	
		r =(pagina/l) + 1;
		
		//printf("%d\t",l);
		//printf("%d\n",pagina);
		printf("%d\n",r);
		pagina = 0;//zera o numero de paginas
		r =0;
	}
	return 0;
}
/*	URI Online Judge | 1222
*	Concurso de Contos
*	Maratona de Programação da SBC  Brasil
*	
*	Timelimit: 1
*	Machado gosta muito de escrever. Já escreveu muitos contos, resenhas, relatos de viagens que fez, além de um pequeno romance. Agora Machado quer participar de um concurso de contos, que tem regras muito rígidas sobre o formato de submissão do conto. As regras do concurso especificam o número máximo de caracteres por linha, o número máximo de linhas por página, além de limitar o número total de páginas. Adicionalmente, cada palavra deve ser escrita integralmente em uma linha (ou seja, a palavra não pode ser separada silabicamente em duas linhas). Machado quer escrever um conto com o maior número de palavras possível, dentro das regras do concurso, e precisa de sua ajuda. Dados o número máximo de caracteres por linha, o número máximo de linhas por página, e as palavras do conto que Machado está escrevendo, ele quer saber o número mínimo de páginas que seu conto utilizaria seguindo as regras do concurso.
*	
*	Entrada
*	A primeira linha de um caso de teste contém três inteiros N (2 ≤ N ≤ 1000), L (1 ≤ L ≤ 30 ) e C (1 ≤ C ≤ 70) , que indicam, respectivamente, o número de palavras do conto de Machado, o número máximo de linhas por página e o número máximo de caracteres por linha. O conto de Machado é inovador e não contém nenhum caractere além de letras maiúsculas e minúsculas e espaços em branco, sem letras acentuadas e sem cedilha. A segunda linha contém o conto de Machado, composto de N palavras (1 ≤ comprimento de cada palavra ≤ C) separadas por espaços em branco; há espaço em branco somente entre duas palavras, e entre duas palavras há exatamente um espaço em branco. O final da entrada é determinado pelo final de arquivo (EOF).
*	
*	Saída
*	Para cada caso de teste imprima uma única linha, contendo um único número inteiro, indicando o número mínimo de páginas que o conto de Machado ocupa, considerando as regras do concurso.
*	
*	Exemplo de Entrada	

*		14 4 20
*		Se mana Piedade tem casado com Quincas Borba apenas me daria uma esperanca colateral
*		16 3 30
*		No dia seguinte entrou a dizer de mim nomes feios e acabou alcunhando me Dom Casmurro
*		5 2 2
*		a de i de o
*		5 2 2
*		a e i o u

*	Exemplo de Saída
*		2
*		1
*		3
*		3
*/