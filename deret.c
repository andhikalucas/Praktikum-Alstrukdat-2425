// Nicholas Andhika Lucas 13523014
// Program menerima bil int a,b dan mengoperasikan bilangan a hingga <= b
#include <stdio.h>
int main(){
int a, b;
scanf("%d %d", &a, &b);
if ((1 <= a) && (b <= 1000) && (a < b)){
    printf("%d", a);
    while(a < b){
        if (a % 2 == 0){
            a = a * 2;
        }
        else if (a % 2 == 1){
            a = a + 1;
        }
        if (a <= b){
        printf(" %d", a);}
    }
printf("\n");
}
return 0;
}