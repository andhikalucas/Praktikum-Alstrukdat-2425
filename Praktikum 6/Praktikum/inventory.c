#include <stdio.h>
#include "boolean.h"
#include "stack.h"

// HINT: Gunakan (c - '0') untuk mengubah character ke angka

int main(){
    int n;
    scanf("%d", &n);
    char ch;
    Stack s;
    CreateEmpty(&s);

    for (int i = 0; i < n; i++){
        scanf(" %c", &ch);

        // Not Bil. Bulat
        if (ch == '+'){
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

        else if (ch == 'X'){
            int apalah;
            Pop(&s, &apalah);
        }

        else if (ch == 'S'){
            int val;
            int sum = 0;
            while(!IsEmpty(s)){
                Pop(&s, &val);
                sum += val;
            }
            // EOP : S empty
            Push(&s, sum);
        }

        else if (ch == 'A'){
            int val;
            int sum = 0;
            int count = 0;
            if (!IsEmpty(s)){
                while(!IsEmpty(s)){
                Pop(&s, &val);
                sum += val;
                count++;
                }
                // EOP : S empty
                Push(&s, sum/count);
            }
        }

        // Bil. Bulat
        else{  //(ch >= 48 && ch <= 57)
            if (ch >= 48 && ch <= 57) Push(&s, ch - '0');
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
    return 0;
}
