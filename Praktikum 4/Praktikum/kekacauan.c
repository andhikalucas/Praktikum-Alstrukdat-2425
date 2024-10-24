#include <stdio.h>
#include "matrix.h"

const int MOD = 1e9 + 7;

int main(){
    Matrix m;
    int n;
    scanf("%d", &n);
    createMatrix(n, n, &m);
    readMatrix(&m, n, n);

    int kekacauan = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // Check only if != 0 (ada benteng)
            if (ELMT(m,i,j) != 0){
            // Check per benteng
            for (int a = 0; a < n; a++){ // untuk looping index 0-i
                if (ELMT(m,i,a) != 0 && a != j){
                    kekacauan += ELMT(m,i,a);
                    kekacauan %= MOD;
                }
                if (ELMT(m,a,j) != 0 && a != i){
                    kekacauan += ELMT(m,a,j) % MOD; // cek baris yg sama
                    kekacauan %= MOD;
                }
            }
            }
        }
    }
    printf("%d\n", kekacauan);
    return 0;
}