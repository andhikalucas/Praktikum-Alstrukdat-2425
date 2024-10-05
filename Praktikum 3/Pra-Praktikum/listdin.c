#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (int*) malloc(CAPACITY(*l) * sizeof(ElType));
}

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
    return listLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (i >= IDX_MIN && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l){
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */

void readList(ListDin *l){
    int n;
    IdxType i;
    do{
        scanf("%d", &n);
    }
    while (n < 0 || n > CAPACITY(*l));
    NEFF(*l) = n;
    for(i=0; i < NEFF(*l); i++){
        scanf("%d", &ELMT(*l,i));
    }
}

void printList(ListDin l){
    IdxType i;
    printf("[");
    for(i = 0; i <= getLastIdx(l); i++){
        printf("%d", ELMT(l,i));
        if (i < getLastIdx(l)){printf(",");}
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    IdxType i;
    ListDin l;
    CreateListDin(&l, CAPACITY(l1));
    NEFF(l) = NEFF(l1);
    for (i=0; i < listLength(l1); i++){
        if (plus){
            ELMT(l,i) = ELMT(l1,i) + ELMT(l2,i);
        }
        else{
            ELMT(l,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
    IdxType i;
    if (listLength(l1) != listLength(l2)){
        return false;
    }
    else{
        for (i=0; i < listLength(l1); i++){
            if (ELMT(l1,i) != ELMT(l2,i)){
                return false;
            }
        }
        return true;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
    IdxType i;
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l,i) == val){
            return i;
        }
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
    IdxType i;
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l,i) > *max){ *max = ELMT(l,i);}
        if (ELMT(l,i) < *min){ *min = ELMT(l,i);}
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
    IdxType i;
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < listLength(lIn); i++) {
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}

ElType sumList(ListDin l){
    int sum = 0;
    IdxType i;
    for (i = 0; i < listLength(l); i++){
        sum += ELMT(l,i);
    }
    return sum;
}

int countVal(ListDin l, ElType val){
    int count = 0;
    IdxType i;
    for (i = 0; i < listLength(l); i++){
        if (ELMT(l,i) == val){
            count++;
        }
    }
    return count;
}

/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
    // bubble sort
    IdxType iterate, i;
    ElType temp;
    for (iterate = 0; iterate < getLastIdx(*l); iterate++){
        for (i = 0; i < getLastIdx(*l) - iterate; i++){
            if ((asc && ELMT(*l,i) > ELMT(*l,i+1)) || (!asc && ELMT(*l,i) < (ELMT(*l, i+1)))){
                temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, i+1);
                ELMT(*l, i+1) = temp;
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
    ELMT(*l, getLastIdx(*l) + 1) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;

}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
// sebaiknya avoid realloc soalnya prone to problems
void expandList(ListDin *l, int num){
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, CAPACITY(L) + num);
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l,i) = ELMT(L,i);
    }
    /*BUFFER(*l) = (int*) realloc (BUFFER(*l), CAPACITY(*l) + num * sizeof(int));
    CAPACITY(*l) += num;*/
}

void shrinkList(ListDin *l, int num){
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, CAPACITY(L) - num);
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l,i) = ELMT(L,i);
    }
    /*BUFFER(*l) = (int*) realloc (BUFFER(*l), CAPACITY(*l) - num * sizeof(int));
    CAPACITY(*l) -= num;*/
}

void compressList(ListDin *l){
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, NEFF(L));
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l,i) = ELMT(L,i);
    }
    /*BUFFER(*l) = (int*) realloc (BUFFER(*l), NEFF(*l) * sizeof(int));
    CAPACITY(*l) = NEFF(*l);*/
}