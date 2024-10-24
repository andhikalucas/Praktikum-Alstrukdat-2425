#include <stdio.h>
#include "listdin.h"

    int main(){
        ListDin l,result;

        // Create list and result list
        int i,j, n1, n2;
        CreateListDin(&l, 1000);
        readList(&l);
        compressList(&l);
        CreateListDin(&result, NEFF(l) + 2);

        // Scan new interval
        scanf("%d %d", &n1, &n2); // n1 = interval start, n2 = interval end
        boolean inserted = false;

        for (i = 0; i < listLength(l); i += 2) {
            int currentStart = ELMT(l, i);
            int currentEnd = ELMT(l, i + 1);

            // If current interval > new interval, insert
            if (currentStart > n2 && !inserted) {
                insertLast(&result, n1);
                insertLast(&result, n2);
                inserted = 1;
            }

            // If intersect between result interval and current interval
            if (listLength(result) > 0 && ELMT(result, getLastIdx(result)) >= currentStart) {
                if (ELMT(result, getLastIdx(result)) < currentEnd) {
                    ELMT(result, getLastIdx(result)) = currentEnd;
                }
            }

            // If intersect new Interval and current interval
            if (!inserted && currentEnd >= n1 && n2 >= currentStart) {
                inserted = 1;
                if (currentStart > n1) {
                    currentStart = n1;
                }
                if (currentEnd < n2) {
                    currentEnd = n2;
                }
            }

            insertLast(&result, currentStart);
            insertLast(&result, currentEnd);
        }

        if (!inserted) {
            insertLast(&result, n1);
            insertLast(&result, n2);
        }

        for (i = 0; i < listLength(result); i++) {
            if (i != listLength(result) - 1) 
                printf("%d ", ELMT(result, i));
            else 
                printf("%d\n", ELMT(result, i));
        }

}