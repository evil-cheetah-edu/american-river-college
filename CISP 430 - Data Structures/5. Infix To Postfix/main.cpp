#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node
{
   char item;
   node *next;
};

bool isOperand(char c);
void readFile(string &inPut);

void  pop(struct node *&top);
void push(struct node *&top, char item);

int  precedence(char c);

void   popStack(struct node *&top, string &resultant, char currOperator = 0);
string evaluateExpression(string inPut);


ifstream in("input.txt");

int main()
{
   string input  = "",
          result = "";

   cout << "Reading the file..." << endl << endl;
   readFile(input);

   cout << "Given expression:" << endl
        << input << endl;
     
   result = evaluateExpression(input);
   
   cout << "Evaluated to Postfix Notation:" << endl;
   cout << result << endl;

   in.close();
   
   return 0;
}


bool isOperand(char c)
{
   ///[48, 57]  is 0..9
   ///[65, 90]  is A..Z
   ///[97, 122] is a..z
   return ((48 <= c && c <= 57) || 
           (65 <= c && c <= 90) ||
           (97 <= c && c <= 122));
}

void readFile(string &inPut)
{
   if (in)
   {
      getline(in, inPut);
   }
}

///Stack functions
void  pop(struct node *&top)
{
   struct node *temp;
   if (top)
   {
      temp = top;
      top  = top->next;
      delete temp;
   }
}

void push(struct node *&top, char item)
{
   struct node *newNode = new node;

   newNode->item = item;
   newNode->next = top;
   top = newNode;
}
//////////////////


int precedence(char c)
{
   switch(c)
   {
      case('+'):
      case('-'):
         return 1;

      case('*'):
      case('/'):
         return 2;

      ///Even the brackets
      ///Brackets are treated in evaluateExpression()
      default:
         return 0;
   }
}

///Adds the stack values to the string
void popStack(struct node *&top, string &resultant, char currOperator)
{
   while(top && precedence(currOperator) <= precedence(top->item))
   {
      if ( !(top->item == '(' || top->item == ')') )
         resultant += top->item;

      pop(top);
   }
}


///Evaluates the expression
string evaluateExpression(string inPut)
{
   struct node *top = NULL;
   string resultant = "";

   for (unsigned i = 0; i < inPut.size(); ++i)
   {
      if ( isOperand(inPut[i]) )
         resultant += inPut[i];

      else
      {
         ///Is stack Empty?
         if (!top)
            ///Then Push
            push(top, inPut[i]);

         ///Is it open Parenthesis?
         else if (inPut[i] == '(')
            ///Then Push
            push(top, inPut[i]);
         
         ///Is it close Parenthesis?
         else if (inPut[i] == ')')
            ///Then Pop
            popStack(top, resultant);
         
         ///Is Precedence of Curr operator is >= than top operator?
         else if ( precedence(inPut[i]) > precedence(top->item) )
            ///Then Push
            push(top, inPut[i]);
         
         ///Is Precedence of Curr Operator is < than top operator?
         else if ( precedence(inPut[i]) <= precedence(top->item) )
         {
            ///Pop the stack, put everyting in resultant
            ///Push Curr to stack
            popStack(top, resultant, inPut[i]);
            push(top, inPut[i]);
         }

       }
    }
    ///Pop any other operators that are left in the stack
    popStack(top, resultant);

    return resultant;
}

