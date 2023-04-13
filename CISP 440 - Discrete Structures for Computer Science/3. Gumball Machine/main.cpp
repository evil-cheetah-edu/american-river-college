#include <iostream>


using namespace std;


/**
 * Enum for Machine State
 */
enum Q
{
    q0,
    q5,
    q10,
    q15,
    q20
};

/**
 * Set of strings corresponding to Machine State
 */
const string Q_STRINGS[] = {
    "q0",
    "q5",
    "q10",
    "q15",
    "q20"
};


/**
 * Enum for Machine Action
 */
enum O
{
    GUMBALL,
    RETURN,
    MESSAGE,
    NONE,
    INVALID
};

/**
 * Set of strings corresponding to Machine Action 
 */
const string O_STRINGS[] = {
    "Gumball dispensed.  Have a nice day.\n",
    "Exact change required.  Returning coin.\n",
    "Insufficient funds.  Cannot buy.\n",
    "",
    "Invalid input.\n"
};


/**
 * Enum for Coins 
 */
enum I
{
    NICKEL,
    DIME,
    BUY,
    QUIT
};

/**
 * Set of strings corresponding to Coins 
 */
const string I_STRINGS[] = {
    "NICKEL",
    "DIME",
    "BUY",
    "QUIT"
};


/// Initial Prompt message to a User
const string PROMPT_STRING = "NICKEL, DIME, BUY, or QUIT: ";


int main()
{
    Q q = q0;
    O o;
    string input = "";
    string output = "";

    cout << PROMPT_STRING;
    cin >> input;

    while(input != I_STRINGS[QUIT])
    {
        if (
            input != I_STRINGS[BUY]    ||
            input != I_STRINGS[NICKEL] ||
            input != I_STRINGS[DIME]   ||
            input != I_STRINGS[QUIT]
        )
            o = INVALID;


        /// Check if State is Q0
        if      (q == q0 && input == I_STRINGS[NICKEL])
        {   q = q5;  o = NONE;  }

        else if (q == q0 && input == I_STRINGS[DIME])
        {   q = q10; o = NONE;  }

        else if (q == q0 && input == I_STRINGS[BUY])
            o = MESSAGE;


        /// Check if State is Q5
        else if (q == q5 && input == I_STRINGS[NICKEL])
        {   q = q10; o = NONE;  }

        else if (q == q5 && input == I_STRINGS[BUY])
            o = MESSAGE;

        else if (q == q5 && input == I_STRINGS[DIME])
        {   q = q15; o = NONE;  }


        /// Check if State is Q10
        else if (q == q10 && input == I_STRINGS[NICKEL])
        {   q = q15; o = NONE;  }

        else if (q == q10 && input == I_STRINGS[DIME])
        {   q = q20; o = NONE;  }

        else if (q == q10 && input == I_STRINGS[BUY])
            o = MESSAGE;


        /// Check if State is Q15
        else if (q == q15 && input == I_STRINGS[NICKEL])
        {   q = q20; o = NONE;  }

        else if (q == q15 && input == I_STRINGS[DIME])
            o = RETURN;

        else if (q == q15 && input == I_STRINGS[BUY])
            o = MESSAGE;


        /// Check if State is Q20
        else if (q == q20 && input == I_STRINGS[BUY])
        {   q = q0;  o = GUMBALL;  }
        else if (q == q20 && ( input == I_STRINGS[NICKEL] || input == I_STRINGS[DIME]))
            o = RETURN;


        /// Set message based on `o` Enum
        if (o == MESSAGE)
                output = O_STRINGS[o];
        else if (o == RETURN)
                output = O_STRINGS[o];
        else if (o == GUMBALL)
                output = O_STRINGS[o];
        else if (o == NONE)
                output = O_STRINGS[o];
        else if (o == INVALID)
                output = O_STRINGS[o];


        cout << output << endl;
        cout << "Current state: " << Q_STRINGS[q] << endl;
        cout << PROMPT_STRING;
        cin >> input;
    }

    return 0;
}