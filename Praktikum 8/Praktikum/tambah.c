#include "listlinier.c"
#include <stdio.h>

int main(){
    List l1, l2;
    CreateList(&l1);
    CreateList(&l2);

    int n1;
    // First line
    scanf("%d", &n1);
    while (n1 != -1){
        if (n1 >= 0) insertLast(&l1, n1);
        if (isEmpty(l1) && n1 == 0){

        }
        scanf(" %d", &n1);
    }

    // Second line
    int n2;
    scanf("%d", &n2);
    while (n2 != -1){
        if (n2 >= 0) insertLast(&l2, n2);
        scanf(" %d", &n2);
    }

    // Agar bisa dijumlahkan, samakan length kedua list. List yang angka lebih kecil diisi dengan 0 di depannya
    while (length(l1) != length(l2)){
        if (length(l1) < length(l2)) insertFirst(&l1, 0);
        else if (length(l2) < length(l1)) insertFirst(&l2, 0);
    }

    // Penjumlahan dari belakang, starting from last index. Remainder/sisa penjumlahan ditambahkan ke depan
    int i, addition, sisa = 0;
    List sum;
    CreateList(&sum);
    for (i = length(l1) - 1; i >= 0; i--){
        // Menjumlahkan hasil dengan sisa yang ada dari penjumlahan sebelumnya
        addition = getElmt(l1, i) + getElmt(l2, i) + sisa;
        // Set sisa kembali ke 0
        sisa = 0;
        if (addition >= 10){ // Jika penjumlahan bersisa
            sisa = 1;
            addition -= 10;
        }
        insertFirst(&sum, addition);
    }
    // Handling untuk case 99 + 1 = 100: ada sisa dan digit pertama adalah 0
    if (sisa == 1 && getElmt(sum, 0) == 0){
        insertFirst(&sum, 1);
    }

    // Print value in list
    Address p = sum;
    while (p != NULL){
        printf("%d", INFO(p));
        if (NEXT(p) != NULL) printf(" ");
        p = NEXT(p);
    }
    printf("\n");
    return 0;
}