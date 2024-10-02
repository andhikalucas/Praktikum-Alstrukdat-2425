#include "fraction.h"
#include <stdio.h>

boolean IsFRACTIONValid(int N, int D){
    return (D != 0);
}
/* Mengirim TRUE jika pecahan valid */

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R){
    Numerator(*F) = N;
    Denominator(*F) = R;
}
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */

void ReadFRACTION(FRACTION *F){
    int N, R;
    scanf("%d %d", &N, &R);
    while (!IsFRACTIONValid(N, R)){
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &N, &R);
    }
    CreateFRACTION(F, N, R);
}
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */


void WriteFRACTION(FRACTION F){
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
}
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE hasil dalam bentuk paling sederhana
 */

/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */
FRACTION AddFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    Numerator(F) = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator (F1);
    Denominator(F) = Denominator(F1) * Denominator(F2);
    return SimplifyFRACTION(F);
}
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    Numerator(F) = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator (F1);
    Denominator(F) = Denominator(F1) * Denominator(F2);
    return SimplifyFRACTION(F);
}


/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    Numerator(F) = Numerator(F1) * Numerator(F2);
    Denominator(F) = Denominator(F1) * Denominator(F2);
    return SimplifyFRACTION(F);
}
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
    FRACTION F;
    Numerator(F) = Numerator(F1) * Denominator(F2);
    Denominator(F) = Denominator(F1) * Numerator(F2);
    return SimplifyFRACTION(F);
}
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
    Numerator(F1) *= n;
    return SimplifyFRACTION(F1);
}
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

FRACTION SimplifyFRACTION(FRACTION F){
    int fpb = GCD(abs(Numerator(F)), abs(Denominator(F)));

    Numerator(F) /= fpb;
    Denominator(F) /= fpb;

    if (Denominator(F) < 0){
        Denominator(F) *= -1;
        Numerator(F) *= -1;
    }
    return F;
    }

/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */

float ToDecimal(FRACTION F){
    return (float) Numerator(F) / (float) Denominator(F);
}
/* Mengonversi FRACTION ke bentuk desimal */