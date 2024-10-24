#include <stdio.h>
#include "boolean.h"
#include "listdin.c"

int main() {
    ListDin l, leftl, rightl;
    int i, j, current;
    int count = 0;
    CreateListDin(&l, 100000);
    readList(&l);
    compressList(&l);
    CreateListDin(&leftl, NEFF(l));
    CreateListDin(&rightl, NEFF(l));
    NEFF(leftl) = NEFF(l);
    NEFF(rightl) = NEFF(l);

    // Input the max/min element for each index
    ELMT(leftl, 0) = ELMT(l, 0);
    ELMT(rightl, getLastIdx(l)) = ELMT(l, getLastIdx(l));

    for (i = 1; i <= getLastIdx(l); i++){
        // Check max left
        if (ELMT(l,i) > ELMT(leftl, i-1)){
            ELMT(leftl, i) = ELMT(l,i);
        }
        else{
            ELMT(leftl, i) = ELMT(leftl, i-1);
        }

        // Check min right
        if (ELMT(l,getLastIdx(l)-i) < ELMT(rightl, getLastIdx(l) + 1 - i)){
            ELMT(rightl, getLastIdx(l) - i) = ELMT(l, getLastIdx(l) - i);
        }
        else{
            ELMT(rightl, getLastIdx(l)-i) = ELMT(rightl, getLastIdx(l)+1-i);
        }
    }
    
    for (i = 0; i <= getLastIdx(l); i++){
        int left_max = -1;
        if (i > 0) left_max = ELMT(leftl, i-1);

        int right_min = 1000000;
        if (i < getLastIdx(l)-1) right_min = ELMT(rightl, i+1);

        if (right_min > ELMT(l, i) && left_max < ELMT(l, i)) {
            count++;
        }
    }
    printf("%d\n", count);


    /*
    // NESTED LOOP SOLUTION (RTE)
    for (i = 0; i < listLength(l); i++){
        boolean kiri = true;
        boolean kanan = true;
        current = ELMT(l,i);
        // cek kiri
        if (i != 0){
            j = i - 1; // start cek dari index kirinya
            while (j >= 0){
                if (current < ELMT(l,j)){
                    kiri = false;
                    break;
                    }
                j--;
            }
        }
        // cek kanan
        if (i != getLastIdx(l)){
            j = i + 1; // start cek dari index kanannya
            while (j <= getLastIdx(l)){
                if (current >= ELMT(l,j)) {
                    kanan = false;
                    break;
                    }
                j++;
            }
        }
        if (kiri == true && kanan == true) count++;
    }
    printf("%d\n", count);
    */
    return 0;
}