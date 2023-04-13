#include "Vector.h"

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
