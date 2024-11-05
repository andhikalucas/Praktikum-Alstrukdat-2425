#include "stack.h"
#include "stack.c"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char cc[n];
    scanf("%s", cc);

    Stack s;
    CreateEmpty(&s);
    boolean valid = true;

    // Edge case handling untuk n ganjil
    if (n % 2 == 1){
        printf("Invalid\n");
    }
    else{ // n genap
        for (int i = 0; i < n; i++){
            
            // Push closing bracket if it's an opening bracket
            if (cc[i] == '('){
                Push(&s, ')');
            }
            if (cc[i] == '{'){
                Push(&s, '}');
            }
            if (cc[i] == '['){
                Push(&s, ']');
            }
            
            // If closing bracket, check if stack top has the proper/same closing bracket
            if (cc[i] == ')' || cc[i] == '}' || cc[i] || ']'){
                // Edge case kasus closing bracket as char pertama
                if (isEmpty(s)){
                    valid = false;
                    break;  
                }
                else{
                int val;
                Pop(&s, &val);
                if (val != cc[i]){
                    valid = false;
                    break;
                }
                }
            }
        }
        // Valid if true and all closing brackets has been popped (semua ada pasangannya)
        if (valid == true && isEmpty(s)) printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}