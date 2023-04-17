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
    ///Makes it work with negatives as well
    if (number < 0)
    {
        cout << '-';
        number *= -1;
    }

    ///Displays the first part of the Number
    if (number < 1000)
        cout << number;

    ///Everything else goes after it with comma
    else
    {
        commaNum(number / 1000);
        cout << ',' << number % 1000;
    }

}
