/**
 * Eugene Moshchyn
 * CISP 400 - MW 5:30 pm
 * Programming Project #3
 * March 13, 2019
**/


#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include <iostream>
using namespace std;

class Rational
{
   public:
      Rational();
      Rational(long long P, long long Q = 1);
      Rational(const Rational&);

      Rational& operator=  (const Rational&);
      Rational& operator+= (const Rational&);
      Rational& operator-= (const Rational&);
      Rational& operator*= (const Rational&);
      Rational& operator/= (const Rational&);

      friend ostream& operator<< (ostream&, const Rational&);
      friend istream& operator>> (istream&, Rational&);

      Rational operator+ (const Rational&) const;
      Rational operator+ (long long) const;
      friend Rational operator+ (long long, const Rational&);

      Rational operator- (const Rational&) const;
      Rational operator- (long long) const;
      friend Rational operator- (long long, const Rational&);

      Rational operator* (const Rational&) const;
      Rational operator* (long long) const;
      friend Rational operator* (long long, const Rational&);

      Rational operator/ (const Rational&) const;
      Rational operator/ (long long) const;
      friend Rational operator/ (long long, const Rational&);

      bool operator== (const Rational&) const;
      bool operator== (long long) const;
      friend bool operator== (long long, const Rational&);

      bool operator!= (const Rational&) const;
      bool operator!= (long long) const;
      friend bool operator!= (long long, const Rational&);

      bool operator> (const Rational&) const;
      bool operator> (long long) const;
      friend bool operator> (long long, const Rational&);

      bool operator< (const Rational&) const;
      bool operator< (long long) const;
      friend bool operator< (long long, const Rational&);

      bool operator>= (const Rational&) const;
      bool operator>= (long long) const;
      friend bool operator>= (long long, const Rational&);

      bool operator<= (const Rational&) const;
      bool operator<= (long long) const;
      friend bool operator<= (long long, const Rational&);

      Rational  operator++ (int); //post
      Rational  operator-- (int); //post
      Rational& operator++ ();    //pre
      Rational& operator-- ();    //pre
      Rational  operator-  () const;
      Rational  operator+  () const;

      Rational pow(unsigned exp) const; //return (*this)^exp
      Rational inverse() const;         //return (*this)^-1


   private:
      void _verify();
      long long _p;
      long long _q;
};

#endif
