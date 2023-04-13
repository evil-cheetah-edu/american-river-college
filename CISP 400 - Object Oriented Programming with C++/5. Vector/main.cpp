/**
 * Eugene Moshchyn
 * Programming Projects 6 & 7
 * CISP 400 - MW 5:30 - 6:50 pm
 * May 15, 2019
**/

#include "Vector.h"
#include "Vector.cpp"


using namespace std;


int main()
{
    int aaa[5];
    for (int i = 0; i < 5; ++i)
        aaa[i] = i * 3;

    Vector<int> v(aaa, 5, -5);

    v.Insert(555, -4);
    cout << v << endl;

    return 0;
}
