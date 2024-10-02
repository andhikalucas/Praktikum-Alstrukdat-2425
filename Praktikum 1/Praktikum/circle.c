#include <stdio.h>
#include "circle.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R){
    return R > 0;
}

/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    CreatePoint(&Center(*C), X, Y);
    Radius(*C) = R;
}
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C){
    float X, Y, R;
    do {
        scanf("%f %f %f", &X, &Y, &R);
    if (!IsCIRCLEValid(X, Y, R)) {
        printf("CIRCLE tidak valid\n");
        }
    } 
    while (!IsCIRCLEValid(X, Y, R));
    CreateCIRCLE(C, X, Y, R);
}
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C){
    return 2 * 3.14 * Radius(C);
}
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */

float Area(CIRCLE C){
    return 3.14 * Radius(C) * Radius(C);
}
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    return Panjang(Center(C), P) < Radius(C);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
    float dist = Panjang(Center(C), P);
    return fabs(dist - Radius(C)) < 1e-5; 
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    return d + Radius(C1) < Radius(C2) || d + Radius(C2) < Radius(C1);
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    float r_sum = Radius(C1) + Radius(C2);
    float r_diff = fabs(Radius(C1) - Radius(C2));
    return fabs(d - r_sum) < 1e-5 || fabs(d - r_diff) < 1e-5;
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float d = Panjang(Center(C1), Center(C2));
    float r_sum = Radius(C1) + Radius(C2);
    float r_diff = fabs(Radius(C1) - Radius(C2));
    return d < r_sum && d > r_diff;
}