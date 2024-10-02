#include <stdio.h>
#include "fraction.h"
#include "fraction.c"

int main(){
  FRACTION F1, F2;
  printf("Masukan F1 x y r: ");
  ReadFRACTION(&F1);
  printf("Masukan F2 x y r: ");
  ReadFRACTION(&F2);
  printf("\nFraction 1: ");
  WriteFRACTION(F1);
  printf(" Fraction 2: ");
  WriteFRACTION(F2);
  printf("\n\n");

  printf("\nF1 + F2: ");
  AddFRACTION(F1, F2);
  printf("\nF1 - F2: ");
  SubtractFRACTION(F1, F2);
  printf("\nF1 * F2: ");
  MultiplyFRACTION(F1, F2);
  printf("\nF1 / F2: ");
  DivideFRACTION(F1, F2);
  printf("\nF1 * 3");
  MultiplyNumberFRACTION(3, F1);
  printf("\nF1 Decimal");
  ToDecimal(F1);
}