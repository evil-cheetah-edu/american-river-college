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


/**
 * Brief: Initializes a course table with all combinations
 * 
 * Uses bitwise operators to get a boolean value of a cell
 * based on its indeces
 * 
 * Initially based on: https://bit.ly/3KVCRwj
 * More on that: https://bit.ly/406NmRI 
 */
void initTable(bool table[1024][10])
{
    ///Initial was (i >> j) & 1
    for (unsigned i = 0; i < 1024; ++i)
        for (unsigned j = 0; j < 10; ++j)
            table[i][9 - j] = !((i >> j) & 1);

}

/**
 * Brief: Prints full table
 * 
 * Used for debugging purposes.
 */
void printTable(bool table[1024][10])
{
    for (unsigned i = 0; i < 1024; ++i)
        printRow(table[i]);
}


/**
 * Brief: Prints a single row
 * 
 * Used for debugging purposes
 */
void printRow(bool row[10])
{
    for (unsigned i = 0; i < 10; ++i)
        cout << (row[i] ? 'T' : 'F') << ' ';

    cout << endl;
}


/**
 * Brief: Checks the criteria from the requirements
 * 
 * Initially, checks if the course exists exactly
 * one time. Then checks the if combination of
 * courses does not violate the criteria.
 * 
 * Criteria from requirements:
 * - (A, B), (B, E), (D, C), (C, E)
 */
bool isRowSat(bool row[10])
{
    return (
        /// Subject A
        (row[0] || row[1]) && !(row[0] && row[1]) &&
        /// Subject B
        (row[2] || row[3]) && !(row[2] && row[3]) &&
        /// Subject C
        (row[4] || row[5]) && !(row[4] && row[5]) &&
        /// Subject D
        (row[6] || row[7]) && !(row[6] && row[7]) &&
        /// Subject E
        (row[8] || row[9]) && !(row[8] && row[9]) &&

        /// Check criteria (A, B)
        !(row[0] && row[2]) && !(row[1] && row[3]) &&
        /// Check criteria (B, E)
        !(row[2] && row[8]) && !(row[3] && row[9]) &&
        /// Check criteria (D, C)
        !(row[6] && row[4]) && !(row[7] && row[5]) &&
        /// Check criteria (C, E)
        !(row[4] && row[8]) && !(row[5] && row[9])
    );
}