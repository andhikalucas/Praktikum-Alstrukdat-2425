#include "stack.c"
#include <stdio.h>
/* Ide Besar: push semua character ke stack word. jika ada kasus duplicate character n[...], dia akan diparsing ke dalam array,
   kemudian diinsert lagi ke stack word original (dan dimultiply).*/
int main(){
    Stack num, word;
    CreateEmpty(&num);
    CreateEmpty(&word);

    int n;
    scanf("%d", &n);
    char cc[n];
    scanf("%s", cc);
    
    for (int i = 0; i < n; i++){
        // Jika character berupa angka, simpan angka multiplier ke stack number
        if (cc[i] >= '0' && cc[i] <= '9'){
            Push(&num, cc[i]);
        }
        
        // Jika character berupa alphabet atau [, simpan ke word stack
        else if (cc[i] >= 'a' && cc[i] <= 'z' || cc[i] == '['){
            Push(&word, cc[i]);
        }

        // Jika character adalah ], akan dilakukan parsing pada characters yang ada sebelum [
        else if (cc[i] == ']'){
            // Copy characters into array
            char array[MaxEl];
            int len_array = 0;
            while (InfoTop(word) != '['){
                Pop(&word, &array[len_array]);
                len_array++;
            }

            // Pop remaining [
            char closebracket;
            Pop(&word, &closebracket);

            // Reorder array ke original characters, karena stack yang dicopy ke array akan bersifat terbalik
            for (int j = 0; j < len_array / 2; j++){
                char temp = array[j];
                array[j] = array[len_array-j-1];
                array[len_array-j-1] = temp;
            }

            // Push array to word stack dengan di duplicate sebanyak multiply kali
            char multiply;
            Pop(&num, &multiply);
            for (int outer_loop = 0; outer_loop < multiply - '0'; outer_loop++){
                for (int j = 0; j < len_array; j++){
                    Push(&word, array[j]);
                }
            }
        }
    }

    // Copy stack to array biar bisa diprint
    char array_all[MaxEl];
    int len_array_all = 0;
    while (!IsEmpty(word)){
        Pop(&word, &array_all[len_array_all]);
        len_array_all++;
    }
    
    // Print dari belakang (sifat stack terbalik)
    for (int i = len_array_all - 1; i >= 0; i--){
        printf("%c", array_all[i]);
    }
    printf("\n");
    return 0;
}