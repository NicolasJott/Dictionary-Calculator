#include "fraction.h"

int32_t gcd(int32_t a, int32_t b) {
    int32_t
            r;

    // make sure a and b are not negative
    a = (a < 0) ? -a : a; //if an is negative, flip it to positive
    b = (b < 0) ? -b : b; //if b is negative, flip it to positive

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}


Fraction::Fraction(int32_t _numerator, int32_t _denominator) {

    int32_t
            g;

    if (_denominator < 0) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }

    g = gcd(_numerator, _denominator);

    numerator = _numerator / g;
    denominator = _denominator / g;

}


Fraction Fraction::operator + (Fraction rhs) {
    int32_t
            s, t;

    s = numerator * rhs.denominator + rhs.numerator * denominator;
    t = denominator * rhs.denominator;

    return Fraction(s, t);
}

Fraction Fraction::operator += (Fraction rhs) {
    int32_t
            s, t;

    s = numerator * rhs.denominator + rhs.numerator * denominator;
    t = denominator * rhs.denominator;

    return rhs + Fraction(s, t);
}

Fraction Fraction::operator - (Fraction rhs) {
    int32_t
            s, t;

    s = numerator * rhs.denominator - rhs.numerator * denominator;
    t = denominator * rhs.denominator;

    return Fraction(s, t);
}

Fraction Fraction::operator * (Fraction rhs) {
    int32_t
            s, t;

    s = numerator * rhs.numerator;
    t = denominator * rhs.denominator;

    return Fraction(s, t);
}

Fraction Fraction::operator / (Fraction rhs) {
    int32_t
            s, t;

    s = numerator * rhs.denominator;
    t = denominator * rhs.numerator;

    return Fraction(s, t);
}

Fraction& Fraction::operator = (Fraction rhs) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
    return *this;

}

bool Fraction::operator == (Fraction rhs) {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Fraction::operator != (Fraction rhs) {
    return numerator != rhs.numerator || denominator != rhs.denominator;

}
bool Fraction::operator <= (Fraction rhs) {
    return numerator * rhs.denominator <= denominator * rhs.numerator;
}

bool Fraction::operator >= (Fraction rhs) {
    return numerator * rhs.denominator >= denominator * rhs.numerator;
}
bool Fraction::operator < (Fraction rhs) {

    return numerator * rhs.denominator < denominator* rhs.numerator;
}
bool Fraction::operator > (Fraction rhs) {

    return numerator * rhs.denominator > denominator * rhs.numerator;
}

std::istream& operator >> (std::istream& is, Fraction& f) {
    int32_t
            n, d;
    char
            slash;

    is >> n >> slash >> d;

    f = Fraction(n, d);

    return is;

}
std::ostream& operator << (std::ostream& os, Fraction f) {

    os << f.getNum() << " / " << f.getDen();

    return os;
}
