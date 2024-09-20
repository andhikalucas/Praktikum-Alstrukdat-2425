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
