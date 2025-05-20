#include <stdio.h>
#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq){
    return (IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq){
    return (((IDX_TAIL(pq) + 1) % CAPACITY) == IDX_HEAD(pq));
}

int length(PrioQueue pq){
    if (isEmpty(pq)) return 0;
    if (isFull(pq)) return CAPACITY;
    return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1 + CAPACITY) % CAPACITY;
}

void enqueue(PrioQueue *pq, ElType val){
    // If the prioqueue is empty
    if(isEmpty(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        HEAD(*pq) = val;
    }

    // If the prioqueue is not empty and is not full yet
    else {
        int i = IDX_TAIL(*pq);
        IDX_TAIL(*pq) += 1; // IDX_TAIL ditambah 1, karena kita akan menambahkan satu elemen baru
        IDX_TAIL(*pq) %= CAPACITY; // Moduluskan dengan CAPACITY agar IDX_TAIL tidak melebihi kapasitas buffer
        boolean found = false;
        while (i != IDX_HEAD(*pq) && !found) {
            if (pq->buffer[i] < val) {
                int p = pq->buffer[i];
                pq->buffer[(i+1) % CAPACITY] = p;
                i += ((CAPACITY - 1));
                i %= CAPACITY;
            }
            else {
                pq->buffer[(i+1) % CAPACITY] = val;
                found = true;
            }
        }
        if (!found) {
            if (HEAD(*pq) < val) {
                pq->buffer[(i+1) % CAPACITY] = HEAD(*pq);
                HEAD(*pq) = val;
            }
            else {
                pq->buffer[(i+1) % CAPACITY] = val;
            }
        }
    }

}

void dequeue(PrioQueue *pq, ElType *val){
    *val = HEAD(*pq);
    if (length(*pq) == 1) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq) = ((IDX_HEAD(*pq) + 1) % CAPACITY);
    }
}

void displayPrioQueue(PrioQueue pq){
    int i, val, len = length(pq);
    printf("[");
    for (i = 0; i < len; i++){
        dequeue(&pq, &val);
        printf("%d", val);
        if (i < len-1) printf(",");
    }
    printf("]\n");
}
