
#include <stdlib.h>
#include <string.h>
 
int main(){
    int count, a, b;
    int i, j, k, l;
 
    int error;
 
    char emojis[101][16];
    char text[1000];
 
    while (1){
        error = scanf("%d %d", &a, &b);
 
        if (a==0 && b==0) break;
 
        for (j=0;j<a;j++){
            error = scanf("%s", emojis[j]);
        }
 
        fgetc(stdin);
 
        count = 0;
        //---------------------------------------------------------
        for (i=0;i<b;i++){
            if (fgets(text, 100, stdin) == NULL){
                ;
            }
 
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