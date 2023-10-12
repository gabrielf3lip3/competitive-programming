#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <stdint.h>

typedef struct rational_t {
    int numerator;
    int denominator;
} rational_t;

int gcd(int a, int b);
rational_t reduce(rational_t t);
rational_t add(rational_t t1, rational_t t2);
rational_t subtract(rational_t t1, rational_t t2);
rational_t multiply(rational_t t1, rational_t t2);
rational_t divide(rational_t t1, rational_t t2);
rational_t absolute(rational_t t);
rational_t exp_rational(rational_t exp, int16_t base);
float exp_real(uint16_t exp, rational_t base);

#endif
