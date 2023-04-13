#include <iostream>
#include <string>


using namespace std;


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
   ///Precondition: "...will be integers and > 0"
   unsigned userInput;
   struct node *top = NULL;

   cout << "Enter the number:" << endl;
   cin >> userInput;
  
   cout << endl << endl;


   cout << "Your Number:    " << userInput << endl;
   cout << "In Binary:      " << decToBin(top, userInput) << endl;
   cout << "In Hexadecimal: " << decToHex(top, userInput) << endl;

   return 0;
}


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


void push(struct node *&top, char item)
{
   struct node *newNode = new node;

   newNode->data = item;
   newNode->next = top;

   top = newNode;
}


string decToBin(struct node *&top, unsigned userInput)
{
   while(userInput != 0)
   {
      char temp;
      ///0 or 1 in ASCII table
      temp = userInput % 2 + 48;
      push(top, temp);
      
      userInput /= 2;
   }
   
   return stackToString(top);
}


string decToHex(struct node *&top, unsigned userInput)
{
   string converted = "";

   while (userInput != 0)
   {
      char temp;
      temp = userInput % 16;
      
      ///If hex-val is a number
      if (temp < 10)
         push(top, (temp + 48));
      
      ///If hex-val is a letter
      else
         push(top, (temp + 55));
      
      userInput /= 16;
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