// Nicholas Andhika Lucas 13523014
// Program menerima bil int n,a,b dan menghasilkan deret bilangan bukan fibonacci ke-n
#include <stdio.h>
int main(){
int n, a, b, f,i;
scanf("%d %d %d", &n, &a, &b);
if ((1 <= n) && (n <= 20) && (1 <= a) && (1 <= b) && (a <= 100) && (b <= 100) && (a <= b)){
    if (n == 1){
        f = a;
    }
    else if (n==2){
        f = b;
    }
    else {
        for(i=3; i<=n; i++){
            f = b + a;
            a = b;
            b = f;
        }
    }
printf("%d\n", f);
}

return 0;
}