#include <iostream>
using namespace std;

enum Q{q0, q5, q10, q15, q20};
enum O{GUMBALL, RETURN, MESSAGE, NONE, INVALID};
enum I{NICKEL, DIME, BUY, QUIT};

const string Q_STRINGS[] = {"q0", "q5", "q10", "q15", "q20"};
const string O_STRINGS[] = {"Gumball dispensed.  Have a nice day.\n",
                            "Exact change required.  Returning coin.\n",
                            "Insufficient funds.  Cannot buy.\n",
                            "",
                            "Invalid input.\n"};
const string I_STRINGS[] = {"NICKEL", "DIME", "BUY", "QUIT"};

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

        ///assign output and q based on current state and input

        if (input != I_STRINGS[BUY] || input != I_STRINGS[NICKEL] || input != I_STRINGS[DIME] || input != I_STRINGS[QUIT] )
             o = INVALID;


        if (q == q0 && input == I_STRINGS[NICKEL])
            {q = q5;
             o = NONE;}
        else if (q == q0 && input == I_STRINGS[DIME])
            {q = q10;
             o = NONE;}
        else if (q == q0 && input == I_STRINGS[BUY])
             o = MESSAGE;


        else if (q == q5 && input == I_STRINGS[NICKEL])
            {q = q10;
             o = NONE;}
        else if (q == q5 && input == I_STRINGS[BUY])
            o = MESSAGE;
        else if (q == q5 && input == I_STRINGS[DIME])
            {q = q15;
             o = NONE;}


        else if (q == q10 && input == I_STRINGS[NICKEL])
            {q = q15;
             o = NONE;}
        else if (q == q10 && input == I_STRINGS[DIME])
            {q = q20;
             o = NONE;}
        else if (q == q10 && input == I_STRINGS[BUY])
            o = MESSAGE;

        else if (q == q15 && input == I_STRINGS[NICKEL])
            {q = q20;
             o = NONE;}
        else if (q == q15 && input == I_STRINGS[DIME])
            o = RETURN;
        else if (q == q15 && input == I_STRINGS[BUY])
            o = MESSAGE;

        else if (q == q20 && input == I_STRINGS[BUY])
            {o = GUMBALL;
             q = q0;}
        else if (q == q20 && ( input == I_STRINGS[NICKEL] || input == I_STRINGS[DIME]))
            o = RETURN;


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
