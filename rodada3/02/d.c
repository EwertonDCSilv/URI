#include <stdio.h>
#include<string.h>

void main (){
	int qtd_emoticons, qtd_linhas;
	int i, j,k,l,tam, aux=0, result;
	while(1){
		result=0;
		scanf("%d%d",&qtd_emoticons, &qtd_linhas);
		if(qtd_emoticons==0 && qtd_linhas==0){
			break;
		}
		char emoticons [qtd_emoticons][15];
		char lista[qtd_linhas][15];
		int tamanho_emoticon[qtd_emoticons];
		for(i=0; i<qtd_emoticons; i++){
			scanf("%s",emoticons[i]);
			tam = strlen(emoticons[i]);
			tamanho_emoticon[i]=tam;
			for(j=1; j<=tam;j++){
				lista[i][j-1] = emoticons[i][tam-j];
			}
		}
		for(i=0;i<=qtd_linhas;i++){
			char linha[85];
			fgets(linha, 85, stdin);
			tam = strlen(linha);
			for(j=0;j<tam; j++){
				for(k=0; k<qtd_emoticons; k++){
					if (linha[j]==lista[k][0]){
						aux=1;
						
						for(l=1;l<tamanho_emoticon[k];l++){
							if(linha[j-l]==lista[k][l]){
								aux++;
							}
						}
						if(aux==tamanho_emoticon[k]){
							linha[j]=' ';
							result++;
						}
					}
				}
			}

		}
		printf("%d\n",result);

	}
}