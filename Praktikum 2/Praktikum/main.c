#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l, l2, count;
    int i, idxcount;
    int idx2 = 0;

    readList(&l);
    CreateListStatik(&l2);
    CreateListStatik(&count);
    
    // COPY UNIQUE DIGIT TO L2
    for (i=0; i < listLength(l); i++){
        if (indexOf(l2, ELMT(l,i)) == IDX_UNDEF){ // IF UNIQUE DIGIT
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

    // *** dapet unique digit array l2 dan count kemunculan di array count ***
    int max, max2, min;
    extremeValues(count, &max, &min); // Find highest and lowest count in count array
    
    // Case: ga ada max kedua
    if (max == min){
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    // Case: ada max kedua
    else{
        // Algoritma: set nilai max2 sbg min dari idxmax2 sebagai nilai max2 yang pertama kali muncul. jika ada nilai yg >max2 dan <max dia menjadi nilai max2 baru.
        // Jika ada yang nilainya sama dengan max2, bandingin nilai ELMT nya (array l2), pilih yang paling kecil nilai ELMTnya.
        int idxmax2;
        max2 = min;
        idxmax2= indexOf(count, max2);
        for (i=0; i < listLength(count); i++){
            if (ELMT(count,i) > max2 && ELMT(count,i) < max){
                max2 = ELMT(count,i);
                idxmax2 = i;
            }
            else if (ELMT(count,i) == max2){
                if (ELMT(l2, i) < ELMT(l2, idxmax2)){
                    idxmax2 = i;
                    max2 = ELMT(count,i);
                }
            }
        }
        printf("%d\n", ELMT(l2, idxmax2));
    }
    return 0;
}