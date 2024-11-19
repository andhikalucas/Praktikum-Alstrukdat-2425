#include "listlinier.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);
    char ch;
    int num, apalah, indexofval;
    
    scanf(" %c", &ch);
    while (ch != 'X'){
        if (ch == 'X'){
            break;
        }
        else{
            if (ch == 'P'){
                scanf(" %d", &num);
                insertFirst(&l, num);
            }

            else if (ch == 'I'){
                scanf(" %d", &num);
                insertLast(&l, num);
            }

            else if (ch == 'C'){
                if (!isEmpty(l)) deleteFirst(&l,&apalah);
            }

            else if (ch == 'D'){
                scanf(" %d", &num);
                indexofval = indexOf(l, num);
                if (indexofval != IDX_UNDEF){
                    deleteAt(&l, indexofval, &apalah);
                }
            }
            // loop the scan
            scanf(" %c", &ch);
        }
    }
    displayList(l);
    return 0;
}