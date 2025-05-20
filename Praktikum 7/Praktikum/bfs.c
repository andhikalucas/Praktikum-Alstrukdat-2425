#include <stdio.h>
#include "queue.h"
#include "boolean.h"

const int MAX_SIZE = 100;

int main() {
    int steps = 0;
    ElType current;

    // Queue Untuk "Berjalan"
    Queue q;
    CreateQueue(&q);
    
    boolean isFound = false;                // Flag Menemukan Jalur
    boolean visit[MAX_SIZE][MAX_SIZE];      // Matrix Flag Untuk Menandai Visited
    char grid[MAX_SIZE][MAX_SIZE];          // Matrix Grid
    
    // Input Size Matrix
    int N;
    scanf("%d", &N);

    // Initialize Matrix Flag With False
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            visit[x][y] = false;
        }
    }

    // Input
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            scanf(" %c", &grid[x][y]);
            if (grid[x][y] == 'A') { // Jika A, Masukkan Index A ke Queue, dan Tandai Sebagai Visited
                ElType index;
                index.row = x;
                index.col = y;
                visit[x][y] = true;
                enqueue(&q, index);
            }
        }
    }

    // BFS Algorithm
    while (!isEmpty(q)) {
        int qLength = length(q);
        for (int i = 0; i < qLength; i++) {
            int x = HEAD(q).row;
            int y = HEAD(q).col;
            dequeue(&q, &current);
            if (grid[x][y] == 'B') { // Jika B Ditemukan, Selesaikan BFS
                isFound = true; 
                break;
            } else { // Jika B Belum Ditemukan dan Masih Mencari Jalur
                if (x > 0 && grid[x - 1][y] != '#' && !visit[x - 1][y]) {
                    ElType next;
                    next.row = x - 1;
                    next.col = y;
                    enqueue(&q, next);
                    visit[x - 1][y] = true;
                }
                if (y < N - 1 && grid[x][y + 1] != '#' && !visit[x][y + 1]) {
                    ElType next;
                    next.row = x;
                    next.col = y + 1;
                    enqueue(&q, next);
                    visit[x][y + 1] = true;
                }
                if (x < N - 1 && grid[x + 1][y] != '#' && !visit[x + 1][y]) {
                    ElType next;
                    next.row = x + 1;
                    next.col = y;
                    enqueue(&q, next);
                    visit[x + 1][y] = true;
                }
                if (y > 0 && grid[x][y - 1] != '#' && !visit[x][y - 1]) {
                    ElType next;
                    next.row = x;
                    next.col = y - 1;
                    enqueue(&q, next);
                    visit[x][y] = true;
                }
            }
        }

        // Tambah 1 Step Jika B Belum Ditemukan
        if (!isFound) {
            steps++;
        }
    }

    // Output
    if (isFound) {
        printf("Ya\n");
        printf("%d\n", steps);
    } else {
        printf("Tidak\n");
    }
    return 0;
}