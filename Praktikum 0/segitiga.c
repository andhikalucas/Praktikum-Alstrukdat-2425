// Nicholas Andhika Lucas 13523014
// Program membuat tampilan segitiga terbalik dengan n sebagai tinggi segitiga
#include <stdio.h>
int main(){
    int n,i,j;
    scanf("%d", &n);
    
    if (1 <= n && n<=100) {
        for(i=1; i<=n; i++){
            if (i!=1){
                for (j=1; j<=(i-1); j++){
                    printf(" ");
                }
                for(j = 1; j <= (2*n)-1-(2*(i-1)); j++){
                printf("*");
                }
            }
            else { // i == 1
            for(j = 1; j <= (2*n)-1-(2*(i-1)); j++){
                printf("*");
            }
            }
        printf("\n");
        }
    }
    return 0;
}

/* Alternatif Jawaban
int main(){
    int n;
    scanf("%d", &n);
    int i;
    for (i = n; i > 0; i-=1){
        int j;
        for (j = n - i; j > 0; j--) printf(" ");
        for (j = 0; j < i; j+= 1) printf("*");
        for (j = 1; j < i; j+= 1) printf("*");
        printf("\n");
    }
    return 0;

}
*/
