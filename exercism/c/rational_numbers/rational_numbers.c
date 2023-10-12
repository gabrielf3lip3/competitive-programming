#include "rational_numbers.h"

#include <math.h>
#include <stdlib.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

rational_t reduce(rational_t t) {
    int common = gcd(t.numerator, t.denominator);

    t.numerator /= common;
    t.denominator /= common;

    if(t.denominator < 0) {
        t.numerator = -t.numerator;
        t.denominator = -t.denominator;
    }

    return (rational_t){ t.numerator, t.denominator };
}

rational_t add(rational_t t1, rational_t t2) {
    rational_t ret = {t1.numerator*t2.denominator + t2.numerator*t1.denominator, t1.denominator * t2.denominator};

    return reduce(ret);
}
rational_t subtract(rational_t t1, rational_t t2) {
    rational_t ret = {t1.numerator*t2.denominator - t2.numerator*t1.denominator, t1.denominator * t2.denominator};

    return reduce(ret);
}
rational_t multiply(rational_t t1, rational_t t2) {
    rational_t ret = {t1.numerator * t2.numerator, t1.denominator * t2.denominator};

    return reduce(ret);
}
rational_t divide(rational_t t1, rational_t t2) {
    rational_t ret = {t1.numerator * t2.denominator, t1.denominator * t2.numerator};

    return reduce(ret);
}
rational_t absolute(rational_t t) {
    return reduce((rational_t){ abs(t.numerator), abs(t.denominator) });
}

rational_t exp_rational(rational_t exp, int16_t base) {
    rational_t ret = { exp.numerator, exp.denominator };

    if(base < 0) {
        ret = (rational_t){ exp.denominator, exp.numerator };
        base = -base;
    }

    ret = (rational_t){ pow(ret.numerator, base), pow(ret.denominator, base) };

    return reduce(ret);
}
float exp_real(uint16_t exp, rational_t base) {
    return pow(exp, ((float)base.numerator / base.denominator));
}
