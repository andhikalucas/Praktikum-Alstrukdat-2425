// Nicholas Andhika Lucas 13523014
// Program menerima bil int a,b dan menampilkan operasi bilangan a hingga <= b
#include <stdio.h>
int main(){
int a, b;
scanf("%d %d", &a, &b);
printf("%d", a);
while (a <= b){
    if (a % 2 == 0){
        a *= 2;
    }
    else {a++;}
    if (a <= b){
    printf(" %d", a);}
}
printf("\n");
return 0;
}

/* ALTERNATIF Cara Print
while (a <= b) {

        printf("%d", a);

        if (a%2 == 0) a*=2;

        else a++;

        if (a <= b) printf(" ");

    }
*/
