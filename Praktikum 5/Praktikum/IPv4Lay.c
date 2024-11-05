#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mesinkata.h"

boolean cekStream(Word kata) {
    // Panjang maksimal 50 karakter
    if (kata.Length > 50) return false;

    int oktet_count = 0;
    int count_at = 0;
    char store[51]; 
    strncpy(store, kata.TabWord, kata.Length); // Copy sejumlah karakter n from src to dest
    store[kata.Length] = '\0';

    // Count @
    for (int i = 0; i < kata.Length; i++) {
        if (!((store[i] >= '0' && store[i] <= '9') || store[i] == '@')) {
            return false;
        }
        if (store[i] == '@') {
            count_at++;
        }
    }
    if (count_at != 3) return false;

    // String parsing with delim @
    char *token = strtok(store, "@"); 
    while (token != NULL) {
        if (oktet_count >= 4) return false;

        int panjang = strlen(token);
        if (panjang == 0 || (panjang > 1 && token[0] == '0')) return false; // If leading zero

        int oktet = atoi(token);
        if (oktet < 0 || oktet > 255) return false; // If not 0-255
        
        oktet_count++;
        token = strtok(NULL, "@");
    }
    return oktet_count == 4;
}

int main() {
    STARTWORD();
    boolean first = true;
    while (!EndWord) {
        if (!first) {
            printf(" ");
        }

        if (cekStream(currentWord)) printf("4Lay");
        else printf("ewh");

        first = false;
        ADVWORD();
    }
    printf("\n");
    return 0;
}