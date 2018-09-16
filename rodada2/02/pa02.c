#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontraPadrao(char remove[], char text[],char insert[]){
	int i =0,j=0,k=0,l=0,stop=0;
	int len = strlen(remove);
	int lenText = strlen(text);
	int leniInsert = strlen(insert);
	int *vet_padrao;
	int initag = 0,endtag = 0,indice = 0;

	vet_padrao = calloc(lenText,sizeof(int));
	
	for(i=0;i<lenText;i++){	
	
		//Verifica se as tags sao valida
		if(text[i] == '<'){
			initag = 1;
			endtag = 1;
			indice = i;
		}else if(indice!=i && initag==1 && text[i] == '<'){
			initag = 0;
			endtag = 0;
			indice = i;
		}if(indice!=i && text[i] == '>'){
			endtag = 0;
			initag = 0;
			indice = i;
		}else if(indice!=i && endtag==1 && text[i] == '>'){
			endtag = 0;
			initag = 0;
			indice = i;
		}
		
		if((toupper(text[i]) == toupper(remove[0])) && initag==1 && endtag==1){
			l=0;
			for(j=i;j<lenText;j++){
				if(toupper(text[j])!= toupper(remove[l]))
					break;
				l++;//Conta o numero de interacoes
			}
			j=0;
			if(l==len-1)
				vet_padrao[i] = 1;
		}	
		stop = 0;
	}
	
	for(i=0;i<lenText;i++){
		if(vet_padrao[i] == 1){
			for(k=0;k<(leniInsert);k++){
				if(insert[k] != '\0' && insert[k] != '\n')
					printf("%c",insert[k]);
			}
			i= i +( len -2);
		}else {
			if(text[i] != '\0' && text[i] != '\n')
				printf("%c",text[i]);
		}
	}
}
 
int main(int argc, char* argv[]){
	int i =0,j=0,k=0;
	char insert[110];
	char remove[110];
	char texto[110];
	
	while(1){
		
		if(k==1)
			printf("\n"); 
		if(fgets(remove,110,stdin)==NULL)
			break;
		if(fgets(insert,110,stdin)==NULL)
			break;
		if(fgets(texto,110,stdin)==NULL)
			break;
		encontraPadrao(remove, texto,insert);
		
		
		k=1;
	}
	return 0;
}
/*	URI Online Judge | 1254
*	Substituição de Tag
*	Por TopCoder*  EUA
*	
*	Timelimit: 1
*	Você está no comando de um sistema de documentos que utiliza tags de código numérico para renderizar documentos para impressão. Há um lote de documentos com o texto baseado em tags, que você deve analisar e converter para tags numéricas para a entrada no sistema. Uma tag é iniciada por um caracter '<', que pode ser seguida por letras, números, barras ou espaços, e para finalizar a tag um caracter '>'. As tags não podem ser encaixadas umas nas outras.
*	
*	As seguintes tags não são válidas:
*	">HI", "<a<b>c>", "<a b c><", "<a<b>".
*	
*	As seguintes tags são válidas:
*	"/=<>HI", "/<>H=I<>/", "<><><><>", "<a=/><b==//bb><c223>", "<a b c>".
*	
*	Para as comparações entre caracteres deve ser desconsiderado o case sensitive.
*	
*	Entrada
*	A entrada contém vários casos de teste. Cada caso de teste é composto de três linhas. A primeira linha contém a tag original presente no texto do documento, que irá conter apenas letras (a-z, A-Z), e seu tamanho será entre 1 e 10 caracteres inclusive. A segunda linha contém um valor numérico pela qual a tag original deverá ser substituida, que será um número entre 1 e 1000 inclusive. A terceira e última linha terá entre 1 e 50 caracteres inclusive, e poderá conter os letras (a-z, A-Z), números (0-9), sinal de menor (<), sinal de maior (>), sinais de igual (=), barras (/), ou espaços em branco. Todos os '<' e '>' são usados apenas em tags.
*	
*	Saída
*	Converto o texto do documento que é dado na entrada, utilizando as específicações dadas acima e imprima em uma única linha, o novo texto do documento com as novas tags, para maiores esclarecimentos consulte o exemplo abaixo.
*	
*	Exemplo de Entrada	Exemplo de Saída
*	BODY
*	10
*	<><BODY garbage>body</BODY>
*	aBc
*	923
*	<dont replacethis>abcabc<abcabcde>
*	table
*	1
*	<ta>bLe<TaBlewidth=100></table></ta>
*	replace
*	323
*	nothing inside
*	HI
*	667
*	92<HI=/><z==//HIb><cHIhi> 
*	a
*	23
*	<a B c a>
*	b
*	2
*	<b b abc ab c> Mangojata
*	
*	<><10 garbage>body</10>
*	<dont replacethis>abcabc<923923de>
*	<ta>bLe<1width=100></1></ta>
*	nothing inside
*	92<667=/><z==//667b><c667667> 
*	<23 B c 23>
*	<2 2 a2c a2 c> Mangojata
*/