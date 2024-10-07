#include <stdio.h>
#include "liststatik.h"
#include <math.h>
int main(){
    ListStatik l;
    int i;
    readList(&l);
    ELMT(l, getLastIdx(l)) ++;
    for (i=getLastIdx(l); i > 0; i--){
        if (ELMT(l,i) == 10){
            ELMT(l,i) = 0;
            ELMT(l, i-1) ++;
        }
    }
    if (ELMT(l, 0) == 10){
        ELMT(l,0) = 0;
        insertFirst(&l, 1);
    }
    printf("%d", ELMT(l, 0));
    for (i=1; i<listLength(l); i++){
        printf(" %d", ELMT(l,i));
    }
    printf("\n");
    return 0;
}