#include <stdio.h>

int main(void) {
  int x = 0;
  int y = 1;
  int n;
  int c = 2;
  printf("%i", x);
  printf("%i", y);
  while (c <= 6){
    n = x + y;
    x = y;
    y = n;
    printf("%i", y);
    c += 1;
  }
}