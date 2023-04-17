#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node
{
   node*  prev;
   string name;
   node*  next;
};

///Enum for output type
enum OUTPUT_TYPE {ASCENDING, DESCENDING};


void   readIn(struct node* &head, struct node* &tail);
void deleteNodeWithName(string input, struct node* &head, struct node* &tail);

bool isEqual(string a, string b);
string toLowercase(string a);

void insertDouble(string studentName, struct node* &head, struct node* &tail);
void  cleanUp(struct node* &head, struct node* &tail);

void traverse(struct node* &head, struct node* &taili, OUTPUT_TYPE type = ASCENDING);



ifstream in("input.txt");

int main()
{
   struct node *head, *tail;
   head = tail = NULL;

   readIn(head, tail);

   cout << "Ascending order:" << endl;
   traverse(head, tail, ASCENDING);
   cout << endl;

   cout << "Descending order:" << endl;
   traverse(head, tail, DESCENDING);
   cout << endl;


   cleanUp(head, tail);

   in.close();

   return 0;
}


///Reads the data in from the file
void readIn(struct node* &head, struct node* &tail)
{
   string input;
   while (in >> input)
   {
      if (input != "delete")
         insertDouble(input, head, tail);

      else
      {
         in >> input;
         deleteNodeWithName(input, head, tail);
      }
   }

   cout << endl << endl;
   cout << "Readin complete..." << endl << endl;
}

///Deletes the Node with particular name
void deleteNodeWithName(string input, struct node* &head, struct node* &tail)
{
   struct node* curr = head;

   cout << "Deleting from the list: " << input << endl;
   ///Checks if list consist of anything
   if (!curr)
   {
      cout << "List is empty..." << endl;
      return;
   }
   else
   {
      while (curr)
      {
         ///Found match => delete it
         if (isEqual(curr->name, input))
         {
            ///Is situated inbetween Head and Tail
            if (curr->next && curr->prev)
            {
               curr->prev->next = curr->next;
               curr->next->prev = curr->prev;
            }
            ///Is situated at Position of Head
            else if (!curr->prev)
            {
               curr->next->prev = NULL;
               head = curr->next;
            }
            ///Is situated at position of Tail
            else if (!curr->next)
            {
               curr->prev->next = NULL;
               tail = curr->prev;
            }
            ///deletes after match and terminates the funcion
            delete curr;
            return;
         }
         ///Not found => go to next
         else
            curr = curr->next;
      }
      ///If goes through the list and founds nothing
      ///=>Element doesn't exist in the list
      cout << "There is no person on the list with name: " << input << endl;
   }
}


///Compares two strings without case sensitivity
bool isEqual(string a, string b)
{
   a = toLowercase(a);
   b = toLowercase(b);

   return a == b;
}


///From Uppercase to Lowercase using ASCII table
string toLowercase(string a)
{
   for (unsigned i = 0; i < a.size(); ++i)
      if ('A' <= a[i] && a[i] <= 'Z')
         ///'a' - 'A' = 32
         a[i] += 32;

   return a;
}

void insertDouble(string studentName, struct node* &head, struct node* &tail)
{
   node* newNode = new node;
   newNode->name = studentName;

   cout << "Inserting into list: " << studentName << endl;

   if (!head)
   {
      ///Emptyness
      newNode->prev = NULL;
      newNode->next = NULL;
      head = newNode;
      tail = newNode;
   }
   else if (studentName < head->name)
   {
      ///Don't forget to link them
      head->prev = newNode;
      newNode->prev = NULL;
      newNode->next = head;
      head = newNode;
   }
   else if (studentName > tail->name)
   {
      ///Don't forget to link them
      tail->next = newNode;
      newNode->next = NULL;
      newNode->prev = tail;
      tail = newNode;
   }
   else
   {
      ///Insert in the middle
      struct node* curr;
      curr = head->next;

      while (studentName > curr->name && curr)
         curr = curr->next;

      newNode->next = curr->prev->next;
      newNode->prev = curr->prev;
      newNode->prev->next = newNode;
      newNode->next->prev = newNode;
   }
}


///Cleans up the memory by deleting the linked list
void cleanUp(struct node* &head, struct node* &tail)
{
   struct node* temp = head;

   while (temp != tail)
   {
      temp = temp->next;
      delete temp->prev;
   }
   delete temp;

   head = tail = NULL;
}


///Goes through Linked list and displays
void traverse(struct node* &head, struct node* &tail, OUTPUT_TYPE type)
{
   struct node* temp;

   switch (type)
   {
      case (ASCENDING):
      {
         temp = head;
         while (temp)
         {
            cout << temp->name << endl;
            temp = temp->next;
         }
         break;

      }
      case(DESCENDING):
      {
         temp = tail;
         while (temp)
         {
            cout << temp->name << endl;
            temp = temp->prev;
         }
         break;
      }

      default:
         cout << "Unknown type was passed..." << endl;

   }
}
