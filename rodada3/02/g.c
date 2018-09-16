
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int main(){
    int count, a, b;
    int i=0, j=0, k=0, l=0;
 
    
    char text[1000];
 
    while (1){
		
		scanf("%d",&a);
		scanf("%d",&b);
 
        if (a==0 && b==0) break;
		
		char emojis[a][16];
		
        for (j=0;j<a;j++){
            scanf("%s", emojis[j]);
        }
 
        count = 0;
        //---------------------------------------------------------
        for (i=0;i<b;i++){
            fgets(text, 100, stdin);
            
           
            // Reading the line char by char...
            for (k=0;j<strlen(text)-1;k++){
                if (text[k] == '\0' || text[k] == EOF) break;  
               
                // For all the emojis, look at the text...
                for (j=0;j<a;j++){
                    int emojiLen = strlen(emojis[j]);
                    if (k < emojiLen-1) continue;
 
                    if (text[k] == emojis[j][emojiLen-1]){
                        // Match: the last char
                        int flag = 0;
                       
                        for (l=0;l<emojiLen; l++){
                            if (text[k-l] != emojis[j][(emojiLen-1)-l]){
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 0){
                            count++;
                            text[k] = ' ';
                        }
                    }
                }
            }
        }
 
        printf("%d\n", count);
    }
 
    return 0;
}