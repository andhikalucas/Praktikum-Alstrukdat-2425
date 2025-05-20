#include <stdio.h>
#include "queue.h"

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    CreateQueue(&q);

    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int val;
            scanf(" %d", &val);

            if(isFull(q)){
                printf("Queue Penuh\n");
            } else {
                enqueue(&q, val);
                printf("Enqueue %d Berhasil\n", val);
            }
            
        } else if (op == 2) {
            int val;

            if(isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                dequeue(&q, &val);
                printf("Dequeue %d Berhasil\n", val);
            }
            
        } else if (op == 3) {
            int head;
            head = HEAD(q);

            if(isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                printf("Elemen Awal Queue adalah %d\n", head);
            }
            
        } else if (op == 4) {
            int len;
            len = length(q);
            printf("Ukuran Queue saat ini adalah %d\n", len);

        }
    }

    displayQueue(q);
}