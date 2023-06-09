#include <iostream>
#include <fstream>


using namespace std;


///or input.txt, was kind of unclear in manual
ifstream in("in.txt");
const unsigned MAX_SIZE = 20;


void stringCopy(char *A, char *B);
bool stringCompare(char *A, char *B);
void stringConcatenation (char *A, char *B);
int  stringPosition(char *A, char B);
int  stringLength(char *A);


/**
 * Tests functionality of the implemented functions
 */
int main()
{
   char a[MAX_SIZE],
        b[MAX_SIZE];

	in >> a >> b;
	cout << a << ' ' << b << endl;

 	stringCopy(a,b);
	cout << a << ' ' << b << endl;

	in >> a >> b;
	cout << "A ?= B " << stringCompare(a, b) << endl;

	in >> a >> b;
	stringConcatenation(a, b);
	cout << a << endl;

	in >> a >> b;
	cout << "Char \"" << b[0] 
         << "\" is situated at " << stringPosition(a, b[0])
         << endl;

    in >> a >> b;
    cout << "String length = " << stringLength(a) << endl;
    cout << a << endl;
	in.close();

	return 0;
}


/**
 * Copies the content of `B` into `A`
 */
void stringCopy(char *A, char *B)
{
    unsigned i;

    for (i = 0; B[i] != '\0'; ++i)
        A[i] = B[i];
        
    A[i] = '\0';
}


/**
 * Checks if strings are equal
 */
bool stringCompare(char *A, char *B)
{

    for (unsigned i = 0; A[i] != '\0'; ++i)
        if (A[i] != B[i])
            return false;

    return true;
}


/**
 * Appends content of `B` to `A`
 */
void stringConcatenation(char *A, char *B)
{
    unsigned i;
    for (i = 0; A[i] != '\0'; ++i);

    for (unsigned j = 0; B[j] != '\0'; ++j)
    {
        A[i] = B[j];
        ++i;
    }
    A[i] = '\0';
}


/**
 * Returns an index of char `B` in string `A`
 * If not found, returns `-1` 
 */
int  stringPosition(char *A, char B)
{
    for (unsigned i = 0; A[i] != '\0'; ++i)
        if (A[i] == B)
            return i;

    return -1;
}


/**
 * Obtains the number of characters, and prepends
 * it in the front of the array.
 * 
 * Returns: stringLength
 * 
 * Disclaimer: Has a typo in storing number of
 * characters implementation; however, was an
 * accepted solution 
 */
int stringLength(char *A)
{
    unsigned numChars;
    char temp[MAX_SIZE];

    /// Get number of characters
    for (numChars = 0; A[numChars] != '\0'; ++numChars);

    /// Copy content of `A` into `temp`
    for (unsigned i = 0; i < numChars; ++i)
        temp[i] = A[i];

    /// Store number of characters
    A[0] = char(numChars) + 48;
 
    /// Copy content of `temp` into `A`
    for (unsigned i = 1; i <= numChars; ++i)
        A[i] = temp[i - 1];
 
    A[numChars + 1] = '\0';

    return numChars;
}