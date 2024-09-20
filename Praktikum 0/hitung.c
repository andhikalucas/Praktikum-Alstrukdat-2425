// Nicholas Andhika Lucas 13523014
// Program menerima bil int n,k dan menghitung jumlah dari bilangan sebanyak n yang diinput yang bukan kelipatan dari k
#include <stdio.h>
int main(){
    int n,k,i,a;
    int total = 0;
    scanf("%d %d", &n, &k);

    if (1 <= n,k && n,k <= 10000){
    for(i=1; i<=n; i++){
        scanf("%d", &a);
        if (1 <= a && a <= 10000){
        if (a % k != 0) {
            total += a;
        }
        }
    }
    }
    printf("%d\n", total);
    return 0;
}
