/**
 * Eugene Moshchyn
 * CISP 400 - MW 5:30 pm
 * Programming Project #3
 * March 13, 2019
**/


#include <iostream>
#include "Rational.h"


using namespace std;


/**
 * Gets `Greates common denominator`
*/
long long _gcd(long long a, long long b)
{
    if (b == 0)
        return a;

    return _gcd(b, a % b);
}


Rational::Rational()
{
    _p = 0;
    _q = 1;
}


Rational::Rational(long long P, long long Q)
{
    _p = P;
    _q = Q;
    _verify();
}


Rational::Rational(const Rational& r)
{
    _p = r._p;
    _q = r._q;
}


Rational& Rational::operator=(const Rational& r)
{
    if (this == &r)
        return *this;

    _p = r._p;
    _q = r._q;

    return *this;
}


/**
 * A/B + C/D = ((A*D) + (C*B)) / (B*D)
*/
Rational& Rational::operator+=(const Rational& r)
{
    _p = _p*r._q + r._p*_q;
    _q = _q * r._q;
    _verify();

    return *this;
}


/**
 * A/B - C/D = ((A*D) + (C*B)) / (B*D)
*/
Rational& Rational::operator-=(const Rational& r)
{
    _p = _p*r._q - r._p*_q;
    _q = _q * r._q;
    _verify();

    return *this;
}


/**
 * A/B * C/D = (A*C)/(B*D)
*/
Rational& Rational::operator*=(const Rational& r)
{
    _p *= r._p;
    _q *= r._q;
    _verify();

    return *this;
}


/**
 * A/B : C/D = (A*D)/(B*C)
*/
Rational& Rational::operator/=(const Rational& r)
{
    _p *= r._q;
    _q *= r._p;
    _verify();

    return *this;
}


ostream& operator<<(ostream& os, const Rational& r)
{
    os << r._p << ':' << r._q;
    return os;
}


/**
 * Let user enter `A:B`, where `:` is any char
*/
istream& operator>>(istream& is, Rational& r)
{
    long long P, Q;
    char c;

    is >> P >> c >> Q;
    r = Rational(P, Q);

    return is;
}


Rational Rational::operator+(const Rational& r) const
{
    return Rational(*this) += r;
}


Rational Rational::operator+(long long l) const
{
    return Rational(*this) += Rational(l);
}


Rational operator+(long long l, const Rational& r)
{
    return Rational(l) += r;
}


Rational Rational::operator-(const Rational& r) const
{
    return Rational(*this) -= r;
}


Rational Rational::operator-(long long l) const
{
    return Rational(*this) -= Rational(l);
}


Rational operator-(long long l, const Rational& r)
{
    return Rational(l) -= r;
}


Rational Rational::operator*(const Rational& r) const
{
    return Rational(*this) *= r;
}


Rational Rational::operator*(long long l) const
{
    return Rational(*this) *= Rational(l);
}


Rational operator*(long long l, const Rational& r)
{
    return (Rational(l) *= r);
}


Rational Rational::operator/(const Rational& r) const
{
    return Rational(*this) /= r;
}


Rational Rational::operator/(long long l) const
{
    return Rational(*this) /= Rational(l);
}


Rational operator/(long long l, const Rational& r)
{
    return (Rational(l) /= r);
}


/**
 * A/B ? C/D = (A*D ? C*B)
*/
bool Rational::operator==(const Rational& r) const
{
    return (_p * r._q) == (_q * r._p);
}


bool Rational::operator==(long long l) const
{
    return *this == Rational(l);
}


bool operator==(long long l, const Rational& r)
{
    return Rational(l) == r;
}


bool Rational::operator!=(const Rational& r) const
{
   return !(*this == r);
}

bool Rational::operator!=(long long l) const
{
    return !(*this == Rational(l));
}


bool operator!=(long long l, const Rational& r)
{
    return !(Rational(l) == r);
}


bool Rational::operator>(const Rational& r) const
{
    return (_p * r._q) > (_q * r._p);
}


bool Rational::operator>(long long l) const
{
    return *this > Rational(l);
}


bool operator>(long long l, const Rational& r)
{
    return Rational(l) > r;
}


bool Rational::operator<(const Rational& r) const
{
    return !( *this > r || *this == r );
}


bool Rational::operator<(long long l) const
{
    return !( *this > Rational(l) || *this == Rational(l) );
}


bool operator<(long long l, const Rational& r)
{
    return !( Rational(l) > r || Rational(l) == r );
}


bool Rational::operator>=(const Rational& r) const
{
    return (*this > r) || (*this == r);
}


bool Rational::operator>=(long long l) const
{
    return (*this > Rational(l)) || (*this == Rational(l));
}


bool operator>=(long long l, const Rational& r)
{
    return (Rational(l) > r) || (Rational(l) == r);
}


bool Rational::operator<=(const Rational& r) const
{
    return !( *this > r );
}


bool Rational::operator<=(long long l) const
{
    return !( *this > Rational(l) );
}


bool operator<=(long long l, const Rational& r)
{
    return !( Rational(l) > r );
}


/**
 * Postfix Increment
 * I.e. `i++`
*/
Rational Rational::operator++(int)
{
    Rational temp(*this);
    *this += 1;

    return temp;
}


/**
 * Postfix Decrement
 * I.e. `i--`
*/
Rational  Rational::operator--(int)
{
    Rational temp(*this);
    *this -= 1;

    return temp;
}


/**
 * Prefix Increment
 * I.e. `++i`
*/
Rational& Rational::operator++()
{
    return *this += 1;
}


/**
 * Prefix Decrement
 * I.e. `--i`
*/
Rational& Rational::operator--()
{
    return *this -= 1;
}


Rational  Rational::operator-() const
{
    return Rational(-_p, _q);
}


Rational  Rational::operator+() const
{
    return *this;
}


/**
 * Gets a Rational in power
 * 
 * I.e. (*this) ** exponent
 */
Rational Rational::pow(unsigned exponent) const
{
    if (exponent == 0)
        return Rational(1);
    
    long long P = _p,
              Q = _q;

    for (unsigned i = 1; i < exponent; i++)
    {
        P *= _p;
        Q *= _q;
    }

    return Rational(P, Q);
}


/**
 * Gets an inverse of Rational
 * 
 * I.e. (*this) ** -1
*/
Rational Rational::inverse() const
{
    return Rational(_q, _p);
}


void Rational::_verify()
{
    if (_q == 0)
    {
        cout << "Denomination CANNOT be Zero!"
             << endl << endl;
             
        exit(1);
    }

    long long gcd = _gcd(_p, _q);
    
    _p /= gcd;
    _q /= gcd;

    if (_q < 0)
    {
        _p = -_p;
        _q = -_q;
    }
}
