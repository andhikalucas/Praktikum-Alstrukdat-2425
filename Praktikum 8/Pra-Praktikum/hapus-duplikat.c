#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

List hapusDuplikat(List l)
{
    Address temp1 = NULL;
    Address temp2 = FIRST(l);
    ElType val;
    if (length(l) <= 1)
    {
        return l;
    }
    while (temp2 != NULL)
    {
        if (NEXT(temp2) != NULL && INFO(temp2) == INFO(NEXT(temp2)))
        {
            val = INFO(temp2);
            while ((temp2) != NULL && INFO(temp2) == val)
            {
                if (temp2 == FIRST(l))
                {
                    temp2 = NEXT(temp2);
                    deleteFirst(&l, &val);
                }
                else
                {
                    NEXT(temp1) = NEXT(temp2);
                    free(temp2);
                    temp2 = NEXT(temp1);
                }
            }
        }
        else
        {
            temp1 = temp2;
            temp2 = NEXT(temp2);
        }
    }
    Address temp3;
    temp1 = NULL;
    temp2 = FIRST(l);
    temp3 = temp2;
    while (temp2 != NULL)
    {
        temp3 = NEXT(temp3);
        NEXT(temp2) = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    FIRST(l) = temp1;
    return l;
}

/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */