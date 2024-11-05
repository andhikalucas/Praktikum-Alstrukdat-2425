#include "stack.c"
#include "stack.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char cc[n];
    scanf("%s", cc);

    Stack s,temp;
    CreateEmpty(&s);
    CreateEmpty(&temp);

    for (int i = 0; i < n; i++){
        // Bil. Bulat
        if  (cc[i] >= 48 && cc[i] <= 57){
            Push(&s, cc[i] - 48);
        }
        // Not Bil. Bulat
        else{ 
            if (cc[i] == '+'){
                int val1, val2;
                // Get last 2 numbers from stack
                Pop(&s, &val1);
                Pop(&s, &val2);
                // Return last 2 numbers to stack (aka naikin index topnya balik ajah)
                Top(s) += 2;
                // Get sum and push sum to stack
                int sum = val1 + val2;
                Push(&s, sum);
            }

            if (cc[i] == 'X'){
                int apalah;
                Pop(&s, &apalah);
            }

            if (cc[i] == 'S'){
                int val;
                int sum = 0;
                while(!IsEmpty(s)){
                    Pop(&s, &val);
                    sum += val;
                }
                // EOP : S empty
                Push(&s, sum);
            }

            if (cc[i] == 'A'){
                int val;
                int sum = 0;
                int count = 0;
                while(!IsEmpty(s)){
                    Pop(&s, &val);
                    sum += val;
                    count++;
                }
                // EOP : S empty
                Push(&s, sum/count);
            }
        }
    }
    // Find total of stack
    int sum = 0;
    int val;
    while (!IsEmpty(s)){
        Pop(&s, &val);
        sum += val;
    }
    printf("%d\n", sum);
    // 0 = 48
    // 1 = 49
}