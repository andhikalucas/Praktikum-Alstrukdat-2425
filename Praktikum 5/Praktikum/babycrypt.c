#include "mesinkata.h"
#include <stdio.h>

// 65 - 90 A-Z
// 97 - 122 a-z

void decrypt (int n, Word w) {
    n = n % 26;
    Word temp = w;

    for (int i = 0; i < w.Length; i++) {
        int num = temp.TabWord[i] - n;
        if ((num < 65) && (temp.TabWord[i] >= 65 && temp.TabWord[i] <= 90)) {
            printf("%c", 91 - n + (temp.TabWord[i] - 65));
        }
        else if ((num < 97) && (temp.TabWord[i] >= 97 && temp.TabWord[i] <= 122)) {
            printf("%c", 123 - n + temp.TabWord[i] - 97);
        }
        else if ((num >= 97 && num <= 122) || (num >= 65 && num <= 90)) {
            printf("%c", temp.TabWord[i] - n);
        }
        else printf("%c", temp.TabWord[i]);
    }
}

int main() {
    
    int n;
    scanf("%d", &n);

    Word w;
    STARTWORD();
    w = currentWord;

    while (!EndWord) {
        decrypt(n, w);
        ADVWORD();
        w = currentWord;
        if (!EndWord) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}