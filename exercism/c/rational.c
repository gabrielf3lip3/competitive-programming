#include <stdio.h>
#include <stdint.h>

typedef struct rational_t {
  int numerator;
  int denominator;
} rational_t;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

rational_t reduce(rational_t t) {

    if(gcd(t.numerator, t.denominator)==1)
        return t;

    int common = gcd(t.numerator, t.denominator);
    t.numerator /= common;
    t.denominator /= common;

    return reduce(t);
}
int main() {
  rational_t t = {20, 40};
  t = reduce(t);
  printf("%d/%d\n", t.numerator, t.denominator);

  rational_t t2 = {50, 25};
  t2 = reduce(t2);
  printf("%d/%d\n", t2.numerator, t2.denominator);
}
