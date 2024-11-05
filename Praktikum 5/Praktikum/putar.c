#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

int main(){
    int wordcount = 0;
    boolean needSpace;
    STARTWORD();
    while (!EndWord){
        wordcount++;
        // if kata ke-ganjil
        if (wordcount % 2 == 1){
            Word copy;
            copy.Length = currentWord.Length;
            for (int i = 0; i < currentWord.Length; i++){
                copy.TabWord[i] = currentWord.TabWord[currentWord.Length-1-i];
            }
        // Print inverted word
        if (needSpace){
            printf(" ");
        }
        for (int i = 0; i < copy.Length; i++){
            printf("%c", copy.TabWord[i]);
        needSpace = true;
        }
        
        } else { // GENAP
        if (needSpace){
            printf(" ");
        for (int i = 0; i < currentWord.Length; i++){
            printf("%c", currentWord.TabWord[i]);  
            }
                needSpace = true;
        }
        }

    ADVWORD();
    }
    
    printf("\n");
    return 0;
}