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

const unsigned SINGLE_DIGIT_MONTH_DATE_LENGTH = 7;

string MONTH_ABBREVIATIONS[] = {
    "Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ",
    "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec "
};


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


/**
 * Displays a date in one of two formats:
 *   - MM/DD/YYYY,   AKA `%m/%d/%Y`
 *   - Mon DD, YYYY, AKA `%b %d, %Y`
*/
void displayDate(const Date& date, ostream& out, DATE_STYLE style)
{
    wellFormed(date);

    unsigned month_value = month(date),
             day_value   = day(date),
             year_value  = year(date);

    switch (style)
    {
        case (MM_DD_YYYY):
            if (month_value < 10) { out << '0'; }
            out << month_value << '/';
            if (day_value < 10) { out << '0'; }
            out << day_value   << '/';

            break;
        
        case (MON_DD_YYYY):
            out << MONTH_ABBREVIATIONS[month_value - 1];
            if ( day_value < 10) { out << '0'; }
            out << day_value << ", ";

            break;

        default:
            cout << "Unknown date format" << endl;
            exit(1);
    }

    unsigned num_of_leading_zeros = 4 - numDigits(year_value);

    for (unsigned i = 0; i < num_of_leading_zeros; ++i)
        out << '0';

    out << year_value << endl;
}


/**
 * Increments a date by `1 day`
*/
Date incrementDate(const Date& date)
{
    wellFormed(date);

    unsigned month_value = month(date),
             day_value   = day(date),
             year_value  = year(date);


    if (1 <= day_value && day_value < monthLength(date))
        return makeDate(month_value, ++day_value, year_value);

    
    if (1 <= month_value && month_value < 12)
        return makeDate(++month_value, 01, year_value);


    return makeDate(01, 01, ++year_value);
}


/**
 * Checks if date is within accepted range 
*/
bool wellFormed(const Date& date)
{
    if ( MIN_DATE <= date && date <= MAX_DATE )
        return true;


    cout << "Date Error!"                        << endl
         << "The following date "
         << "DOES NOT fall into accepted range:" << endl
         << date                                 << endl;
    
    exit(1);
}


/**
 * Gets Month numeric value.
 * 
 * Either single digit, or double digit
*/
unsigned month(const Date& date)
{
    wellFormed(date);

    if (numDigits(date) == SINGLE_DIGIT_MONTH_DATE_LENGTH)
        return nthDigit(date, 6);

    return (nthDigit(date, 7) * 10 + nthDigit(date, 6));
}


/**
 * Gets Day numeric value
*/
unsigned day(const Date& date)
{
    wellFormed(date);

    return (nthDigit(date, 5) * 10 + nthDigit(date, 4));
}


/**
 * Gets Year numeric value
*/
unsigned year(const Date& date)
{
    wellFormed(date);

    unsigned year_value = 0;
    for (unsigned i = 3; i > 0; i--)
    {
        year_value += nthDigit(date, i);
        year_value *= 10;
    }
    year_value += nthDigit(date, 0);

    return year_value;
}


/**
 * Determines a leap year by its value
*/
bool isLeapYear(const Date& date)
{
    wellFormed(date);

    if ((year(date) % 400) == 0)
        return true;

    if ((year(date) % 100) == 0)
        return false;

    if ((year(date) % 4) == 0)
        return true;

    return false;
}


/**
 * Gets number of days in month
*/
unsigned monthLength(const Date& date)
{
    wellFormed(date);

    unsigned month_value = month(date);

    if (
        (month_value < 8   && month_value % 2 == 1) ||
        (month_value >= 8  && month_value % 2 == 0)
    )
        return 31;

    if (month_value == 2)
        return ( isLeapYear(date) ? 29 : 28 );

    return 30;
}


/**
 * Checks whether `date1` is less than `date2`
*/
bool lessThan(const Date& date1, const Date& date2)
{
    wellFormed(date1);
    wellFormed(date2);


    if ( year(date1) != year(date2) )
        return year(date1) < year(date2);

    if ( month(date1) != month(date2) )
        return month(date1) < month(date2);

    return day(date1) < day(date2);
}


/**
 * Checks whether the date is Palindrome
*/
bool isPalindrome(const Date& date)
{
    wellFormed(date);

    unsigned number_of_digits = numDigits(date);

    /// Check Date Length to be 8 Digits
    if (number_of_digits != SINGLE_DIGIT_MONTH_DATE_LENGTH)
    {
        for (unsigned i = 0; i < (number_of_digits / 2); i++)
            if ( nthDigit(date, i) != nthDigit(date, number_of_digits - 1 - i) )
                return false;
    }

    /// Date Length is 7 Digits
    if (nthDigit(date, 0) != 0)
        return false;

    for (unsigned i = 1; i < ((number_of_digits + 1) / 2); i++)
        if ( nthDigit(date, i) != nthDigit(date, number_of_digits - i) )
            return false;

   return true;
}