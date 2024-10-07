#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l, l2, count;
    int i, j, idxcount;
    int idx2 = 0;
    readList(&l);
    CreateListStatik(&l2);
    CreateListStatik(&count);

    // COPY UNIQUE DIGIT TO L2
    for (i=0; i < listLength(l); i++){
        if (indexOf(l2, ELMT(l,i)) == IDX_UNDEF){
            ELMT(l2, idx2) = ELMT(l,i); // COPY UNIQUE TO L2
            ELMT(count, idx2) = 0; // INITIALIZE COUNT ARRAY
            idx2 ++;
        }
    }

    // START COUNT PER L2
    for (i=0; i < listLength(l); i++){
        idxcount = indexOf(l2, ELMT(l,i));
        ELMT(count, idxcount) ++;
        }
    
    printList(l2);
    printf("\n");
    for (i=0; i < listLength(l2); i++){
        printf("%d %d\n", ELMT(l2,i), ELMT(count,i));
    }
    return 0;
}