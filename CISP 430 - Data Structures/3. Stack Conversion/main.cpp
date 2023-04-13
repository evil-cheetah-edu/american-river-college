#include <iostream>
#include <string>


using namespace std;


const int BINARY_BASE         =  2;
const int HEXADECIMAL_BASE    = 16; 
const int HEXADECIMAL_LETTER  = 10;

const int ASCII_NUMBER_OFFSET = 48;
const int ASCII_LETTER_OFFSET = 65;


struct node
{
   char data;
   node *next;
};


void   pop(struct node *&top);
void   push(struct node *&top, char item);

string decToBin(struct node *&top, unsigned userNum);

string decToHex(struct node *&top, unsigned userNum);
string stackToString(struct node *&top);


int main()
{
   unsigned userInput;
   struct node *top = nullptr;

   cout << "Enter the number:" << endl;
   cin >> userInput;
  
   cout << endl << endl;
   cout << "Your Number:    " << userInput << endl;
   cout << "In Binary:      " << decToBin(top, userInput) << endl;
   cout << "In Hexadecimal: " << decToHex(top, userInput) << endl;

   return 0;
}


/**
 * Pops top node from stack
 */
void pop(struct node *&top)
{
   struct node *temp;
   
   if(top)
   {
      temp=top;
      top=top->next;
      delete temp;
   }
}


/**
 * Pushes new node to the top of the stack
 */
void push(struct node *&top, char item)
{
   struct node *newNode = new node;

   newNode->data = item;
   newNode->next = top;

   top = newNode;
}


/**
 * Converts a number from Decimal to Binary
 */
string decToBin(struct node *&top, unsigned userInput)
{
   while(userInput != 0)
   {
      char decimal_value;

      decimal_value = userInput % BINARY_BASE + ASCII_NUMBER_OFFSET;
      push(top, decimal_value);
      
      userInput /= BINARY_BASE;
   }
   
   return stackToString(top);
}


/**
 * Converts a number from Decimal to Hexidecimal
 */
string decToHex(struct node *&top, unsigned userInput)
{
   string converted = "";

   while (userInput != 0)
   {
      char decimal_value;
      decimal_value = userInput % HEXADECIMAL_BASE;
      
      ///If hex-val is a number
      if (decimal_value < HEXADECIMAL_LETTER)
         push(top, (decimal_value + ASCII_NUMBER_OFFSET));
      
      ///If hex-val is a letter
      else
         push(top, (decimal_value % HEXADECIMAL_LETTER + ASCII_LETTER_OFFSET));
      
      userInput /= HEXADECIMAL_BASE;
   }

   return stackToString(top);
}


///Function that retuns string based on node vals
string stackToString(struct node *&top)
{
   string result = "";
   while (top)
   {
      result += top->data;
      pop(top);
   }

   return result;
}