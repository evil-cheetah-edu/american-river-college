/**********************************************************
    Eugene Moshchyn
    CISP 430 MW 3:00 - 4:25 pm
    Prof. I. Sabzevary
    Programming Project "Sort Bubble Selection Insertion"
**********************************************************/


#include <iostream>
#include <iomanip>

#define ROWS 5
#define COLS 4

using namespace std;


void outPut(int arr[ROWS][COLS]);
void backUp(int arr[ROWS][COLS]);
void outPutColumn(int arr[ROWS][COLS], int columnIndex);

void        bubble(int arr[ROWS][COLS], int limit,  int colIndex);
void     selection(int arr[ROWS][COLS], int limit,  int colIndex);
void         shell(int arr[ROWS][COLS], int length, int colIndex);
void insertionSort(int arr[ROWS][COLS], int rowIndex);

int binarySearch(int arr[ROWS][COLS], int rowIndex, int key);


///Main()

int main()
{
    int myArray[ROWS][COLS];
    int userChoice, foundIndex;

    cout << "Initializing Array:" << endl;
    backUp(myArray);
    outPut(myArray);
    cin.get();

    cout << "Bubble Sort:" << endl;
    bubble(myArray, ROWS - 1, 0);
    outPut(myArray);
    backUp(myArray);
    cin.get();

    cout << "Selection Sort:" << endl;
    selection(myArray, ROWS - 1, 1);
    outPut(myArray);
    backUp(myArray);
    cin.get();

    cout << "Shell Sort:" << endl;
    shell(myArray, ROWS, 2);
    outPut(myArray);
    backUp(myArray);
    cin.get();

    cout << "Insertion Sort:" << endl;
    insertionSort(myArray, 4);
    outPut(myArray);

    cout << "What number do you want to find in Row #5?" << endl;
    cin >> userChoice;
    cout << endl
         << "Trying to Find..."
         << endl << endl;

    outPutColumn(myArray, binarySearch(myArray, 4, userChoice));

    backUp(myArray);
    cin.get();

    return 0;
}


/**
 * Used to traverse the matrix
**/
void outPut(int arr[ROWS][COLS])
{
    for (unsigned i = 0; i < ROWS; ++i)
    {
        for (unsigned j = 0; j < COLS; ++j)
            cout << setw(3) << arr[i][j] << ' ';

        cout << endl;
    }
    cout << endl;
    return;
}


/**
 * Used to reset matrix to the default state between sorts
**/
void backUp(int arr[ROWS][COLS])
{
    int backUpArray[ROWS][COLS] =
    {
        {5, 3,  2, 16},
        {9, 8, 10, 17},
        {4, 7, 11, 18},
        {2, 5,  9, 12},
        {7, 9,  4, 10}
    };

    for (unsigned i = 0; i < ROWS; ++i)
        for (unsigned j = 0; j < COLS; ++j)
            arr[i][j] = backUpArray[i][j];

    return;
}


/**
 * Outputs specific column
**/
void outPutColumn(int arr[ROWS][COLS], int column_index)
{
    if (column_index < 0)
        throw int(404);

    for (unsigned i = 0; i < ROWS; ++i)
        cout << arr[i][column_index] << endl;
}


/**
 * Bubble Sort
 * 
 * Specifications:
 *  - Default Order: Ascending
**/
void bubble(int array[ROWS][COLS], int limit, int column_index)
{
    int temporary = 0;

    for (; limit > 0; --limit)
        for (unsigned i = 0; i < ROWS - 1; ++i)
        {
            if (array[i][column_index] > array[i + 1][column_index])
            {
                temporary                  = array[  i  ][column_index];
                array[  i  ][column_index] = array[i + 1][column_index];
                array[i + 1][column_index] = temporary;
            }
        }
}


/**
 * Selection Sort
 * 
 * Specifications:
 *  - Default Order: Descending
**/
void selection(int array[ROWS][COLS], int limit, int column_index)
{
    int temporary, largest_index;

 	for(; limit > 0; --limit)
    {
        largest_index = 0;

    	for (unsigned i = 1; i <= limit; ++i)
        {
            if (array[i][column_index] < array[largest_index][column_index])
                largest_index = i;
      	}

		if (limit != largest_index)
        {
            temporary                          = array[limit][column_index];
      		array[limit][column_index]         = array[largest_index][column_index];
      		array[largest_index][column_index] = temporary;
		}
   	}
}


/**
 * Shell Sort
 *
 * Specifications:
 *  - Default Order: Ascending
**/
void shell(int array[ROWS][COLS], int length, int column_index)
{
	int temporary;

	for (int gap = length / 2; gap >= 1; gap /= 2)
		for(int i = gap; i < length; ++i)
			for (
                int j = i;
                (j >= gap) && (array[j - gap][column_index] > array[j][column_index]);
                j -= gap
            )
            {
				temporary                = array[j - gap][colIndex];
				array[j - gap][colIndex] = array[   j   ][colIndex];
				array[   j   ][colIndex] = temporary;
			}
}


/**
 * Insertion Sort
 *
 * Specifications:
 *  - Default Order: Ascending
**/
void insertionSort(int arr[ROWS][COLS], int row_index)
{
	int temporary;

	for (int i = 1; i < COLS - 1; ++i)
    {
		for (
            int j = i;
            (j > 0) && (arr[row_index][j - 1] > arr[row_index][j]);
            --j
        )
        {
			temporary             = arr[row_index][  j  ];
			arr[row_index][  j  ] = arr[row_index][j - 1];
			arr[row_index][j - 1] = temporary;
		}
	}
}


/**
 * Binary Search
**/
int binarySearch(int array[ROWS][COLS], int row_index, int key)
{
    int high = COLS - 1,
         low = 0,
         mid;

    while (high >= low && !found)
    {
        mid = (high + low ) / 2;

        if ( key == array[row_index][mid] )
            return mid;

        if (key > array[row_index][mid])
        {
            low = mid + 1;
            continue;
        }

        high = mid - 1;
    }

    return -1;
}
