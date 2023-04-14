/*********************

Eugene Moshchyn
CISP 400 - MW 5:30 pm
Programming Project #3
March 13, 2019

*********************/


#include <iostream>
#include "Rational.h"
using namespace std;


int main()
{
   //Constructors
   cout << "Default1:\n";
   Rational b;
   cout << "Default2:\n";
   Rational a(2,7);
   cout << "Default3:\n";
   Rational c(1,3);
   Rational d(2,7);

   //Streams
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   cout << "c = " << c << endl;
   cout << "d = " << d << endl;
   cin.get();
   
   //+=, -=, *=, /= Operators
   cout << "_= Operators:\n";
   b = 2;
   cout << "b += 2   = ";
   b += 2;
   cout << b << endl;
   cout << "b -= " << d << "  = ";
   b -= d;
   cout << b << endl;
   cout << "b *= 3   = ";
   b *= 3;
   cout << b << endl;
   cout << "b /= " << d << " = ";
   b /= d;
   cout << b << endl;
   cin.get();
   
   //+-*/  Operators
   b = c;
   cout << "a = " << a << endl;
   cout << "b = " << b << endl << endl;
   cout << "_ Operators:\n";
   cout << a << " + "  << b << " = " << a+b << endl;
   cout << b << " + 3  "    << " = " << b+3 << endl;
   cout <<   "7   + "  << b << " = " << 7+b << endl << endl;

   cout << a << " - "  << b << " = " << a-b << endl;
   cout << b << " - 3  "    << " = " << b-3 << endl;
   cout <<   "7   - "  << b << " = " << 7-b << endl << endl;

   cout << a << " * "  << b << " = " << a*b << endl;
   cout << b << " * 3  "    << " = " << b*3 << endl;
   cout <<   "7   * "  << b << " = " << 7*b << endl << endl;

   cout << a << " / "  << b << " = " << a/b << endl;
   cout << b << " / 3  "    << " = " << b/3 << endl;
   cout <<   "7   / "  << b << " = " << 7/b << endl << endl;
   cin.get();

   //Booleans
   a = Rational(6,1);
   b = Rational(1,6);
   c = Rational(7,6);
   d = a;
   //Simple ones
     //True check
   cout << a << " == " << d << " = " << (a == d) << endl;
   cout << a << " >  " << b << " = " << (a >  b) << endl;
   cout << b << " <  " << a << " = " << (b <  a) << endl;
   cout << a << " != " << b << " = " << (a != b) << endl << endl;
     //False check
   cout << a << " == " << b << " = " << (a == b) << endl;
   cout << b << " >  " << a << " = " << (b >  a) << endl;
   cout << a << " <  " << b << " = " << (a <  b) << endl;
   cout << a << " != " << d << " = " << (a != d) << endl;
   cin.get();
   //Simple with nums
     //True
   cout << a << " == " << 6 << " = " << (a == 6) << endl;
   cout << a << " >  " << 3 << " = " << (a >  3) << endl;
   cout << b << " <  " << 9 << " = " << (b <  9) << endl;
   cout << a << " != " << 2 << " = " << (a != 2) << endl << endl;
     //False
   cout << a << " == " << 2 << " = " << (a == 2) << endl;
   cout << a << " >  " << 7 << " = " << (a >  7) << endl;
   cout << a << " <  " << 3 << " = " << (a <  3) << endl;
   cout << a << " != " << 6 << " = " << (a != 6) << endl << endl;
   cin.get();
   //Nums with Rational
   a = Rational(7,1);
     //True
   cout << 7 << " == " << a << " = " << (7 == a) << endl;
   cout << 8 << " >  " << a << " = " << (8 >  a) << endl;
   cout << 6 << " <  " << a << " = " << (6 <  a) << endl;
   cout << 3 << " != " << a << " = " << (3 != a) << endl << endl;
     //False
   cout << 5 << " == " << a << " = " << (5 == a) << endl;
   cout << 3 << " >  " << a << " = " << (3 >  a) << endl;
   cout << 9 << " <  " << a << " = " << (9 <  a) << endl;
   cout << 7 << " != " << a << " = " << (7 != a) << endl << endl;
   cin.get();

   //>= Operator
   a = Rational(4,1);
   b = Rational(5,1);
   c = Rational(3,1);
   d = a;

   cout << a << " >= " << c << " = " << (a >= c) << endl;
   cout << a << " >= " << d << " = " << (a >= d) << endl;
   cout << a << " >= " << b << " = " << (a >= b) << endl << endl;

   cout << a << " >= " << 2 << " = " << (a >= 2) << endl;
   cout << a << " >= " << 4 << " = " << (a >= 4) << endl;
   cout << a << " >= " << 5 << " = " << (a >= 5) << endl << endl;

   cout << 5 << " >= " << a << " = " << (5 >= a) << endl;
   cout << 4 << " >= " << a << " = " << (4 >= a) << endl;
   cout << 3 << " >= " << a << " = " << (3 >= a) << endl << endl;
   cin.get();

   //<= Operator
   cout << a << " <= " << b << " = " << (a <= b) << endl;
   cout << a << " <= " << d << " = " << (a <= d) << endl;
   cout << a << " <= " << c << " = " << (a <= c) << endl << endl;

   cout << a << " <= " << 6 << " = " << (a <= 6) << endl;
   cout << a << " <= " << 4 << " = " << (a <= 4) << endl;
   cout << a << " <= " << 2 << " = " << (a <= 2) << endl << endl;

   cout << 3 << " <= " << a << " = " << (3 <= a) << endl;
   cout << 4 << " <= " << a << " = " << (4 <= a) << endl;
   cout << 6 << " <= " << a << " = " << (6 <= a) << endl << endl;
   cin.get();
   
   cout << b << endl;
   b++;
   cout << b << endl;
   ++b;
   cout << b << endl;
   b--;
   cout << b << endl;
   --b;
   cout << b << endl << endl;
   cin.get();
   cout << "Enter b:\n";
   cin >> b;
   unsigned i;
   cout << "Enter the power:\n";
   cin >> i;
   cout << b << " in " << i << " power is: " << b.pow(i) << endl;
   cout << "Inverse of " << b << " is " << b.inverse() << endl << endl;
   cout << b << "*(-1) = " << -b << endl;
   b = -b;
   cout << "b = -b -> " << b << endl;
   b = -b;
   cout << "b = -b again -> " << b << endl;
   cout << b << "*(1)  = " << b << endl;


   cout << "End of debugging...\n\n";
   cin.get();


   return 0;
}
