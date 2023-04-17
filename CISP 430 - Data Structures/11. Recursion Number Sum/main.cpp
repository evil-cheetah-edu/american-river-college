/**
 *
 *   Eugene Moshchyn
 *   CISP 430 MW 3:00 - 4:25 pm
 *   Prof. I. Sabzevary
 *   Project "Recursion Number Sum"
 *   October 20, 2019
 *
**/


#include <iostream>


using namespace std;


int numberSum(long long number);


int main()
{
    long long number;

    cout << "Enter the number:" << endl;
    cin  >> number;

    cout << "The sum of the digits is: "
         << numberSum(number) << endl;

    return 0;
}


int numberSum(long long number)
{
    if ( number < 0)
        return numberSum( -number );

    if (number < 9)
    {
        return number;
    }

    return number % 10 + numberSum( number / 10 );
}