#include <iostream>
#include <iomanip>

using namespace std;



void initTable (bool table[1024][10]);
void printTable(bool table[1024][10]);
bool isRowSat(bool row[10]);
void printRow(bool row[10]);


int main()
{
    bool table[1024][10];

    initTable(table);
    printTable(table);

    cout << endl;

    for (unsigned i = 0; i < 1024; ++i)
    {
        if (isRowSat(table[i]))
            printRow(table[i]);
    }


    return 0;
}


void initTable(bool table[1024][10])
{
    ///Initial was (i >> j) & 1
    for (unsigned i = 0; i < 1024; ++i)
        for (unsigned j = 0; j < 10; ++j)
            table[i][9 - j] = !((i >> j) & 1);

}

void printTable(bool table[1024][10])
{
    for (unsigned i = 0; i < 1024; ++i)
    {
        for (unsigned j = 0; j < 10; ++j)
            cout << (table[i][j] ? 'T' : 'F')  << ' ';

        cout << endl;
    }
}

bool isRowSat(bool row[10])
{
    ///False if ((A, B), (B, E), (D, C), (C, E))
    return (///Subject doesn't exist on both periods
            ///A
            (row[0] || row[1]) && !(row[0] && row[1]) &&
            ///B
            (row[2] || row[3]) && !(row[2] && row[3]) &&
            ///C
            (row[4] || row[5]) && !(row[4] && row[5]) &&
            ///D
            (row[6] || row[7]) && !(row[6] && row[7]) &&
            ///E
            (row[8] || row[9]) && !(row[8] && row[9]) &&

            ///(A, B)
            !(row[0] && row[2]) && !(row[1] && row[3]) &&
            ///(B, E)
            !(row[2] && row[8]) && !(row[3] && row[9]) &&
            ///(D, C)
            !(row[6] && row[4]) && !(row[7] && row[5]) &&
            ///(C, E)
            !(row[4] && row[8]) && !(row[5] && row[9])

            );

}

void printRow(bool row[10])
{
    for (unsigned i = 0; i < 10; ++i)
        cout << (row[i] ? 'T' : 'F') << ' ';

    cout << endl;
}
