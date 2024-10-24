#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

int main() {
    ListDin l,l2;
    int i,j, temp;
    int count = 0;
    CreateListDin(&l, 1000);
    readList(&l);
    compressList(&l);
    CreateListDin(&l2, CAPACITY(l));
    NEFF(l2) = NEFF(l);

    for (i=0; i <= getLastIdx(l); i++){
        // copy l to l2
        ELMT(l2,i) = ELMT(l,i);
        // check if l2 needs to be sorted
        if (i != 0 && ELMT(l2,i) < ELMT(l2,i-1)){
            for (j = i; j > 0; j--){
                if (ELMT(l2,j) < ELMT(l2,j-1)){
                    temp = ELMT(l2,j);
                    ELMT(l2,j) = ELMT(l2, j-1);
                    ELMT(l2, j-1) = temp;
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}

/*
    for (i=0; i < listLength(l) - 1; i++){
        // Sorting elmt i
        int idxcount = 0;
        for (j = i; j > 0; j--){
            if (ELMT(l,i) < ELMT(l,j-1)) idxcount++;
        }
        if (idxcount > 0){
            int insertidx = i - idxcount;
            // delete
            int val = ELMT(l,i);
            for (j = i; j < listLength(l)-1; j++){
            ELMT(l, j) = ELMT(l, j+1);
            }
            // insert
            for(j = getLastIdx(l) + 1; j > insertidx; j--){
            ELMT(l, j) = ELMT(l, j-1);
            }
            ELMT(l, ) = val;

        }
        count += idxcount;  
    }
    */  
