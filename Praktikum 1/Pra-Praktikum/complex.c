#include "complex.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im){
/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */
return (Re == Re && Im == Im);
}

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im){
/* Membentuk sebuah COMPLEX dari komponen-komponennya */
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
Real(*C) = Re;
Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C){
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C){
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */
    if (Imag(C) < 0){
    printf("%.2f%.2fi\n", Real(C), Imag(C));
    }
    else {
    printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}
/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil penjumlahan C1 + C2 */
    return (COMPLEX){
    Real(C1) + Real(C2), 
    Imag(C1) + Imag(C2)
    };
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil pengurangan C1 - C2 */
    return (COMPLEX){
        Real(C1) - Real(C2), 
        Imag(C1) - Imag(C2)
    };
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
    return (COMPLEX){
        (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2)),
        (Real(C1) * Imag(C2)) + (Imag(C1) * Real(C2))
    };
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float denom = Real(C2) * Real(C2) + Imag(C2) * Imag(C2);
if (denom == 0){
    return (COMPLEX){0,0};
}   
else{
return (COMPLEX){
    ((Real(C1) * Real(C2)) + (Imag(C1) * Imag(C2))) / denom,
    ((Imag(C1) * Real(C2)) - (Real(C1) * Imag(C2))) / denom
    };
}
}

float AbsCOMPLEX(COMPLEX C){
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */
    return sqrt ((Real(C) * Real(C)) + (Imag(C) * Imag(C)));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C){
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */
    return(COMPLEX){
        Real(C),
        Imag(C) *= (-1)
    };
}

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2){
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */
    return((Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2)));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
/* Mengirimkan true jika C1 tidak sama dengan C2 */
    return ((Real(C1) != Real(C2)) || (Imag(C1) != Imag(C2)));
}
/* ***************************************************************** */
