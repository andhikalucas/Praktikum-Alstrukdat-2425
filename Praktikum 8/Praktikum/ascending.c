#include "listlinier.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    List sort;
    CreateList(&sort);

    // Input to List
    int n;
    scanf(" %d", &n);
    while (n != -9999){
        insertLast(&l, n);
        scanf(" %d", &n);
    }

    // Sort List: find min per iteration and insert to sort list
    Address p;
    int min, idxmin, apalah;
    
    // Loop the insert until list is empty
    while (!isEmpty(l)){
        p = l;
        min = INFO(p); // min = idx 0
        idxmin = 0;

        p = NEXT(p); // start from idx = 1
        int i = 1;
        while (p != NULL){
            if (INFO(p) < min){
                min = INFO(p);
                idxmin = i;
            }
            i++;
            p = NEXT(p);
        }
        insertLast(&sort, min);
        deleteAt(&l, idxmin, &apalah);
    }

    displayList(sort);
    return 0;
}