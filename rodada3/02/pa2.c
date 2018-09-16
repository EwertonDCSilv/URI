#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cont;

void analise(char *texto,char **listEmoj,int *endEmoj,char **invetEmoj,int N){
	int k=0,j=0,l=0,n=0;
	int aux=0;
	int lenT=0;
	
	lenT = strlen(texto);//Comprimento da string

	for(j=0;j<lenT; j++){//Analisando todos os caracteres da string			
		for(k=0; k<N; k++){//Analisando com todos os caracteres de fim de emoji                                 
			if (texto[j]==invetEmoj[k][0]){//Caso sejam iguais executa o processo de troca
				aux=1;                                      
				for(l=1;l<endEmoj[k];l++){                  
					if(texto[j-l]==invetEmoj[k][l])
						aux++;                              
				}               
				if(aux==endEmoj[k]){  //Realiza e conta uma remocao                   
					texto[j]=' ';                        
					cont = cont +1;
				}                                        
			}                                            
		}                                                
	}                                                    
}

int main(){
	int i=0,j=0,N=0,M=0;
	int lenE=0;
	
	char **listEmoj;
	char **invetEmoj;
	int *endEmoj;
	
	while(1){//Define o ciclo
	
		scanf("%i",&N);//Define a quatidade de numeros Emojis
		scanf("%i",&M);//Define a quatidade de numeros Strings
		
		if(N==0 && M==0)//Caso ambos seja verdadeiro finaliza o programa
			break;
		
		//Alocando memoria para estrutruas
		endEmoj  = malloc(N*(sizeof(int*)));//Vetor que guarda a o indice da ultima posição do EMOJI
		listEmoj  = malloc(N*(sizeof(char*)));//Matriz que armazena os EMOJIS
		invetEmoj = malloc(N*(sizeof(char*)));//Matriz que armazena os EMOJIS invertidos
								
				
		for(i=0; i<N; i++){//Recebe e trata os EMOJIS
			
			listEmoj[i] = (char*)malloc(15*sizeof(char));
			invetEmoj[i] = (char*)malloc(15*sizeof(char));
			
			scanf("%s",listEmoj[i]);
			endEmoj[i]= strlen(listEmoj[i]);//Armazena o Indice final do emoji
			lenE = strlen(listEmoj[i]);//Comprimento do emoji

			for(j=1; j<=lenE;j++){//Inverte o EMOJI
				invetEmoj[i][j-1] = listEmoj[i][lenE-j];
			}
		}
		
		for(i=0;i<=M;i++){//Recebe as Strings 
			char texto[100];
			fgets(texto, 100, stdin);
			analise(texto,listEmoj,endEmoj,invetEmoj,N);//Realiza a analise para cada caso
		}		
	
		printf("%i\n",cont);
		cont = 0;
		
		//Libera memoria da Matrix de Emoji original e invertida
		for(i=0; i<N; i++){
			free(listEmoj[i]);
			free(invetEmoj[i]);
		}
		
		free(listEmoj);
		free(endEmoj);
		free(invetEmoj);
	}
	return 0;
}
/*
*	URI Online Judge | 1364
*	Emoticons :-)
*	Por Pablo Heiber  Argentina
*	
*	Timelimit: 3
*	Emoticons são usados em chats e conversações por e-mail para tentar expressar a emoção que palavras impressas não podem. Isso parece interessante para muitos, mas outros acham irritantes e querem se livrar deles.
*	
*	George é uma dessas pessoas. Ele odeia tanto emoticons que ele está preparando um plano para remover todos os emoticons de todos os e-mails do mundo. Já que você compartilha de seus planos visionários você está preparando um programa especial para ele.
*	
*	Seu programa receberá a lista de emoticons para banir. Cada emoticon será uma sequência de caracteres sem incluir qualquer espaço em branco. Você também receberá várias linhas de texto. O que você precisa fazer é mudar alguns caracteres do texto em espaço para certificar-se de que nenhum emoticom ficará no texto. Para um emoticon poder aparecer no texto, é necessário ter uma sequência especial de caracteres consecutivos.
*	
*	Para ajudar o plano de George a manter-se oculto o mais tempo possível, você precisa fazer seu trabalho com o mínimo possível de mudança nos caracteres.
*	
*	Entrada
*	A entrada contém vários casos de teste. Cada teste consiste em várias linhas. A primeira linha de cada caso de teste conterá dois inteiros separados por um espaço: N, o número de emoticons a proibir, e M, o número de linhas que o texto tem. As próximas N linhas contém um emoticon cada, uma sequência (string) "não vazia" de no máximo quinze caracteres. Cada uma das últimas M linhas do caso de teste contém uma linha de texto de no máximo oitenta caracteres. Você pode assumir que 1 ≤ N, M ≤ 100.
*	
*	Caracteres válidos para emoticons são letras maiúsculas e minúsculas, dígitos e símbolos “!?.,:;-_’#$%&/=*+(){}[]” (aspas para demarcar). Cada linha do texto deve conter os mesmos caracteres com a adição de um caractere "espaço".
*	
*	A entrada é terminada por N = M = 0.
*	
*	Saída
*	Para cada caso de teste, imprima exatamente uma linha contendo um único inteiro que indica o número mínimo de mudanças que você precisa fazer para ter certeza de que nenhum emoticon apareça no texto.
*	
*	Exemplo de Entrada	Exemplo de Saída
*	4 6
*	:-)
*	:-(
*	(-:
*	)-:
*	Hello uncle John! :-) :-D
*	I am sad or happy? (-:-(?
*	I feel so happy, my head spins
*	(-:-)(-:-)(-:-)(-:-) :-) (-: :-)
*	but then sadness comes :-(
*	Loves you, Joanna :-)))))
*	3 1
*	:)
*	):
*	))
*	:):)):)):)):(:((:(((:):)
*	0 0
*	
*	11
*	8
*	
*	ACM/ICPC South America Contest 2007.
*/