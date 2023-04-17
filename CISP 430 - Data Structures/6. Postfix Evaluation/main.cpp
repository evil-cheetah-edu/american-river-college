#include <iostream>
#include <string>
#include <fstream>


using namespace std;


ifstream in("input.txt");


struct node
{
   int   item;
   node *next;
};


void  pop(struct node *&top);
void push(struct node *&top, int item);

void readFile(string &inPut);

bool isDigit(char c) { return ('0' <= c && c <= '9'); }
int  charToInt(char c);

int  calc(int a, int b, char oper);
int  evaluateExpression(string &inPut);


int main()
{
    string input = "";
    int result;

    cout << "Reading the file..." << endl << endl;
    readFile(input);

    cout << "Given expression:" << endl
            << input            << endl;

    result = evaluateExpression(input);
    cout << "Result of Postfix Notation:" << endl
         << result                        << endl;

    in.close();
    
    return 0;
}


/**
 * Copy of function from `assingment 3`
**/
void pop(struct node *&top)
{
    struct node *temp;

    if (top)
    {
        temp = top;
        top  = top->next;
        delete temp;
    }
}


/**
 * Copy of function from `assingment 3`
**/
void push(struct node *&top, int item)
{
    struct node *newNode = new node;

    newNode->item = item;
    newNode->next = top;
    top = newNode;
}


void readFile(string &inPut)
{
    if (in)
        getline(in, inPut);
}


/**
 * Converts `char` to `int`
**/
int charToInt(char c)
{
    if ( !isDigit(c) )
        throw int(-1);

    return (c - '0');
}


/**
 * Simple calculator function
**/
int calc(int a, int b, char oper)
{
    switch(oper)
    {
        case('+'):
            return b + a;

        case('-'):
            return b - a;

        case('*'):
            return b * a;

        case('/'):
            return b / a;

        default:
            throw unsigned(501);
    }
}


int evaluateExpression(string &inPut)
{
    struct node *top = NULL;
    int result;

    for (unsigned i = 0; i < inPut.size(); ++i)
    {
            ///Is a number?
            if(isDigit(inPut[i]))
                push( top, charToInt(inPut[i]) );
            
            ///Equal Sign?
            else if (inPut[i] == '=')
                ///Do we have top?
                if (top)
                    return top->item;

                else
                    throw float(13.12);
            

            else
            {
                int a, b;
                ///top
                a = top->item;
                pop(top);
                
                ///bottom
                b = top->item;
                pop(top);
                
                int c = calc(a, b, inPut[i]);
                push(top, c);
            }
    }
    ///top still exists
    result = top->item;
    pop(top);

    return result;
}