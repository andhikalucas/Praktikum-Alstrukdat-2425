#include <stdio.h>
#include "boolean.h"
#include "stack.h"
/* Ide Besar: push semua character ke main stack. jika ada kasus duplicate character k[...], dia akan diparsing ke dalam array,
   kemudian diinsert lagi ke stack word original (setelah dimultiply).*/
int main(){
    Stack main;
    CreateEmpty(&main);

    int n;
    scanf("%d", &n);
    char ch;
    
    int i, k, count, pow_value, len_stack;
    char val, closebracket;
    for (i = 0; i < n; i++){
        scanf(" %c", &ch);

        // Push semua karakter ke main stack hingga menemukan ']'
        if (ch == ']'){

            // Parsing semua karakter yang ada di dalam bracket ke dalam array
            char array[MaxEl];
            int len_array = 0;
            while (InfoTop(main) != '['){
                Pop(&main, &array[len_array]);
                len_array++;
            }

            // Terminasi string dengan '\0' di akhir
            array[len_array] = '\0';

            // Pop remaining '['
            char closebracket;
            Pop(&main, &closebracket);

            // Parsing angka yang ada di belakang '[' (multipliernya). Simpan ke dalam integer k
            k = 0;
            count = 0; // digit ke-berapa, untuk perkalian dengan 10
            while (InfoTop(main) >= '0' && InfoTop(main) <= '9'){
                Pop(&main, &val);
                pow_value = 1;
                // Simple function untuk perpangkatan 10^n
                for (int x = 0; x < count; x++){
                    pow_value *= 10;
                }
                // Jumlahkan k dengan digit yang sudah diset dengan -0 yang benar (puluhan, ratusan, dll)
                k += (val - '0') * pow_value;
                count++;
            }

            // Push character dalam array ke main stack sebanyak k kali
            for (int x = 0; x < k; x++){
                for (int y = len_array - 1; y >= 0; y--){ // Push dari character terakhir sebelum \0 hingga character awal (terbalik)
                    Push(&main, array[y]);
                }
            }

        }
        else{ // Semua karakter selain ']' dipush ke main stack
            Push(&main, ch);
        }
    }
    // Print stack menggunakan buffer dari ADT stack (lebih gampang aja)
    len_stack = Top(main);
    for (i = 0; i <= len_stack; i++){
        printf("%c", main.T[i]);
    }
    printf("\n");
    return 0;
}
