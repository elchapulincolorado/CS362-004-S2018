#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main() {
  int result;

  const int a = 3;
  const int b = 2;
  result = compare(&a, &b);
  if (result == 1) {
    printf("compare() greater than test passed.  3 should have been greater than 2 and it was!\n");
  } else {
    printf("compare() greater than test failed.  3 should have been greater than 2 and it wasn't\n");
  }

  const int c = 2;
  const int d = 3;
  result = compare(&c, &d);
  if (result == -1) {
    printf("compare() less than test passed.  2 should have been less than 3 and it was!\n");
  } else {
    printf("compare() less than test failed.  2 should have been less than 3 and it wasn't\n");
  }

  const int e = 3;
  const int f = 3;
  result = compare(&e, &f);
  if (result == 0) {
    printf("compare() equals test passed.  3 should have equaled 3 and it did!\n");
  } else {
    printf("compare() equals test failed.  3 should have equaled 3 and it didn't\n");
  }

}
