/**
 *
 *   Eugene Moshchyn
 *   CISP 430 MW 3:00 - 4:25 pm
 *   Prof. I. Sabzevary
 *   Project "Recursion Comma"
 *   October 20, 2019
 *
**/


#include <iostream>


using namespace std;


void commaNum(long long number);


int main()
{
    long long userNum;

    cout << "Enter the number:" << endl;
    cin  >> userNum;

    cout << "Your number look like: " << endl;
    commaNum(userNum);

    return 0;
}


void commaNum(long long number)
{
    if (number < 0)
    {
        cout << '-';
        number *= -1;
    }

    if (number < 1000)
    {
        cout << number;
        return;
    }

    commaNum(number / 1000);
    cout << ',' << number % 1000;
}