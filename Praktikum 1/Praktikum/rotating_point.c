# include <stdio.h>
# include "rotating_point.h"
# include <math.h>


COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX nilai;
    nilai.Re = 1.0;
    nilai.Im = 0.0;

        for (int i = 0; i < p; i++) {
        COMPLEX temp; 

        temp.Re = nilai.Re * C.Re - nilai.Im * C.Im;
        temp.Im = nilai.Re * C.Im + nilai.Im * C.Re;

        nilai = temp;
    }

    return nilai;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n){
    if (n == 0) {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }

    for (int i = 1; i <=n; i++){
        COMPLEX pC = PowerCOMPLEX(C,i);

        float X = Absis(*P)*pC.Re - Ordinat(*P)*pC.Im;
        float Y = Absis(*P)*pC.Im + Ordinat(*P)*pC.Re;

        Absis(*P) = X;
        Ordinat(*P) = Y;
        
        if (Absis(*P)*Absis(*P) + Ordinat(*P)*Ordinat(*P) > 1){
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            return;
        }
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}