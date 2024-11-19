#include <stdio.h>
#include "stack.h"

#define MAX_SIZE 10007
int tinggi[MAX_SIZE];                   // Menyimpan ketinggian prajurit
int max[MAX_SIZE];                      // Menyimpan nilai kekuatan prajurit pada subkelompok ukuran X
                                        // Dari soal, kekuatan maksimal adalah prajurit terpendek pada subkelompok
int kiri[MAX_SIZE], kanan[MAX_SIZE];    // Menyimpan indeks batas kiri dan kanan dari rentang

int main() {
    int num;
    scanf("%d", &num); // Banyak prajurit                 

    // 1
    // INISIALISASI
    for (int i = 0; i < num; i++) {
        scanf("%d", &tinggi[i]); // Ketinggian prajurit
        kiri[i] = i;
        kanan[i] = i;
        max[i] = 0;
    }
    // Menambahkan elemen ekstra pada max[] 
    max[num] = 0;

    // 2
    // RENTANG KIRI
    // Menghitung batas kiri untuk setiap elemen tinggi[i]
    // Jika elemen tinggi[i] lebih kecil dari elemen tinggi[i-1] (sebelah kiri lebih kecil atau sama),
    // maka kiri[i] adalah indeks paling kiri dari rentang 
    for (int i = 0; i < num; i++) {
        while (kiri[i] > 0 && tinggi[kiri[i] - 1] >= tinggi[i]) {
            kiri[i] = kiri[kiri[i] - 1];
        }
    }
    
    // 3
    // RENTANG KANAN
    // Menghitung batas kanan untuk setiap elemen tinggi[i]
    // Jika elemen tinggi[i] lebih kecil dari elemen tinggi[i+1] (sebelah kanan lebih tinggi atau sama),
    // maka kanan[i] adalah indeks paling kanan dari rentang
    for (int i = num - 1; i >= 0; i--) {
        while (kanan[i] < num - 1 && tinggi[kanan[i] + 1] >= tinggi[i]) {
            kanan[i] = kanan[kanan[i] + 1];
        }
    }

    // 4
    // SEARCHING KEKUATAN MAKSIMAL
    // Menghitung kekuatan maksimal untuk setiap subkelompoknya
    // Range_size menghitung ukuran rentang
    for (int i = 0; i < num; i++) {
        int range_size = kanan[i] - kiri[i] + 1;
        // Jika tinggi[i] lebih besar nilai yang saat ini disimpan di max[range_size],
        // maka max[range_size] diupdate dengan tinggi[i]
        if (tinggi[i] > max[range_size]) {
            max[range_size] = tinggi[i];
        }
    }

    // 5
    // MEMASTIKAN KEKUATAN MAKSIMAL YANG BENAR
    // Making sure setiap rentang memiliki nilai kekuatan maksimal yang benar
    for (int size = num - 1; size >= 1; size--) {
        if (max[size + 1] > max[size]) {
            max[size] = max[size + 1];
        }
    }

    // 6
    // OUTPUT
    for (int size = 1; size <= num; size++) {
        printf("%d", max[size]);
        if (size < num) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}