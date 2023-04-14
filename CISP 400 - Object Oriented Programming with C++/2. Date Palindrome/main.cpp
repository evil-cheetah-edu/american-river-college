/**
 * Eugene Moshchyn
 * CISP 400 - MW 5:30 pm - 6:50 pm
 * Programming Project #1
 * February 13, 2019 
**/

#include <iostream>


using namespace std;


typedef unsigned Date;


const unsigned MIN_DATE =  1010001;
const unsigned MAX_DATE = 12319999;

const unsigned YEAR_POSITION_START  = 1;
const unsigned DAY_POSITION_START   = YEAR_POSITION_START * 10000;
const unsigned MONTH_POSITION_START = DAY_POSITION_START  *   100;


enum DATE_STYLE {MM_DD_YYYY, MON_DD_YYYY};


unsigned numDigits(unsigned num);
int nthDigit(unsigned num, unsigned nth);
Date makeDate(unsigned m, unsigned d, unsigned y);
void displayDate(const Date& date, ostream& out = cout, DATE_STYLE style = MM_DD_YYYY);
Date incrementDate(const Date& date);
bool wellFormed(const Date& date);
unsigned month(const Date& date);
unsigned day(const Date& date);
unsigned year(const Date& date);
bool isLeapYear(const Date& date);
unsigned monthLength(const Date& date);
bool lessThan(const Date& date1, const Date& date2);
bool isPalindrome(const Date& date);


int main()
{
    Date currDate;
    cout << "Enter the initial date: ";
    cin >> currDate;
    cin.ignore();
    while (currDate < 12312020)
    {
        if ( isPalindrome(currDate) )
        {
            displayDate(currDate);
            cout << " is a palindrome!\n";
            cin.get();

        }
        currDate = incrementDate(currDate);
    }

    return 0;
}


/**
 * Returns the number of digits in the number
*/
unsigned numDigits(unsigned number)
{
    unsigned length = 1;
    
    while ( number > 9 )
    {
        number /= 10;
        ++length;
    }

    return length;
}


/**
 * Returns a digit at index from the back in number
*/
int nthDigit(unsigned number, unsigned index)
{
    for (unsigned i = 0; i < index; i++)
            number /= 10;

    return number % 10;
}


/**
 * Returns a formatted as date unassigned integer
*/
Date makeDate(unsigned month, unsigned day, unsigned year)
{
    return (
        month * MONTH_POSITION_START +
        day   * DAY_POSITION_START   +
        year  * YEAR_POSITION_START
    );
}


void displayDate(const Date& date, ostream& out, DATE_STYLE style)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n";
        exit(1);
    }


    unsigned m = month(date),
             d = day(date),
             y = year(date);

    if (style == MM_DD_YYYY)
    {
        if (m < 10)
                out << '0';
        out << m << '/';
        if (d < 10)
                out << '0';
        out << d << '/';
    }

    else if (style == MON_DD_YYYY)
    {
        string months[] = {"Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ",
                            "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec "};
        out << months[m - 1];
        if ( d < 10)
                out << '0';
        out << d << ", ";
    }


    ///checking for leading zeros
    unsigned zeroNum = 4 - numDigits(y);
    for (unsigned i = 0; i < zeroNum; i++)
        out << '0';
    out << y << endl;
}


Date incrementDate(const Date& date)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n!";
        exit(1);
    }


    unsigned monthNum = month(date),
             dayNum   = day(date),
             yearNum  = year(date);

    if (1 <= dayNum && dayNum < monthLength(date))
        dayNum++;

    else
        if (1 <= monthNum && monthNum < 12)
        {
            dayNum = 1;
            monthNum++;
        }
        else
        {
            dayNum   = 1;
            monthNum = 1;
            yearNum++;
        }

    return makeDate(monthNum, dayNum, yearNum);
}


bool wellFormed(const Date& date)
{
    return (MIN_DATE <= date && date <= MAX_DATE);
}


unsigned month(const Date& date)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n";
        exit(1);
    }


    if (numDigits(date) == 7)
        return nthDigit(date, 6);

    else
        return (nthDigit(date, 7) * 10 + nthDigit(date, 6));
}


unsigned day(const Date& date)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n";
        exit(1);
    }

    return (nthDigit(date, 5) * 10 + nthDigit(date, 4));
}


unsigned year(const Date& date)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n";
        exit(1);
    }

    unsigned yearNum = 0;
    for (unsigned i = 3; i > 0; i--)
    {
        yearNum += nthDigit(date, i);
        yearNum *= 10;
    }
    yearNum += nthDigit(date, 0);

    return yearNum;
}


bool isLeapYear(const Date& date)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n";
        exit(1);
    }

    if ((year(date) % 400) == 0)
        return true;

    else if ((year(date) % 100) == 0)
        return false;

    else if ((year(date) % 4) == 0)
        return true;

    else
        return false;
}


unsigned monthLength(const Date& date)
{
    if ( !wellFormed(date) )
    {
        cout << "Date Error!\n";
        exit(1);
    }

    unsigned monthNum = month(date);
    if ( (monthNum < 8  && monthNum % 2 == 1) || (monthNum >= 8  && monthNum % 2 == 0) )
        return 31;

    if (monthNum == 2)
        return (isLeapYear(date))? 29 : 28;

    return 30;
}


bool lessThan(const Date& date1, const Date& date2)
{
    if ( !wellFormed(date1) )
    {
        cout << "Date #1 Error!\n";
        exit(1);
    }

    if ( !wellFormed(date2) )
    {
        cout << "Date #2 Error!\n";
        exit(1);
    }

    if (year(date1) == year(date2) && month(date1) == month(date2))
        return day(date1) < day(date2);

    else
        if (year(date1) == year(date2))
            return month(date1) < month(date2);
        else
            return year(date1) < year(date2);
}


bool isPalindrome(const Date& date)
{
    if (!wellFormed(date))
    {
        cout << "Date Error!\n";
        exit(1);
    }

    unsigned nums = numDigits(date);
    if (nums == 7)
    {
        if (nthDigit(date, 0) != 0)
            return false;

        for (unsigned i = 1; i < ((nums + 1) / 2); i++)
            if ( nthDigit(date, i) != nthDigit(date, nums - i) )
                return false;
    }

    else
    {
        for (unsigned i = 0; i < (nums / 2); i++)
            if ( nthDigit(date, i) != nthDigit(date, nums - 1 - i) )
                return false;
    }

   return true;
}