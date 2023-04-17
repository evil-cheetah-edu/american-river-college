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


void   readIn(struct node* &head, struct node* &tail);
void traverse(struct node* &head, struct node* &tail);
void insertDouble(string studentName, struct node* &head, struct node* &tail);

void  cleanUp(struct node* &head, struct node* &tail);
void  deleteNodes(unsigned number, struct node* &head, struct node* &tail);
void  deleteFirstNode(struct node* &head, struct node* &tail);

unsigned countNodes(struct node* &head, struct node* &tail);


ifstream in("input.txt");

int main()
{
   struct node *head, *tail;
   head = tail = NULL;

   unsigned userNumber;

   readIn(head, tail);

   traverse(head, tail);
   cout << endl;

   cout << "Linked list consists of " << countNodes(head, tail) << " nodes" << endl;
   cout << "How many do you want to delete?" << endl
        << "(Items will be deleted from beginning)" << endl;
   cin >> userNumber;

   deleteNodes(userNumber, head, tail);

   traverse(head, tail);

   cleanUp(head, tail);
   in.close();

   return 0;
}


///Reads the data in from the file
void readIn(struct node* &head, struct node* &tail)
{
   cout << "Readin begin..." << endl;
   string input;
   while (in >> input)
      insertDouble(input, head, tail);

   cout << endl << endl;
   cout << "Readin complete..." << endl << endl;
}


///Outputs the List values without deleting
void traverse(struct node* &head, struct node* &tail)
{
   if (!head)
      cout << "Unable to output the list..." << endl
           << "List is empty!" << endl;

   else
   {
      cout << "The list contains:" << endl;
      struct node* curr = head;
      do
      {
         cout << curr->name << endl;
         curr = curr->next;
      } while (curr != head);
   }
}

///Inserts Data to the end
void insertDouble(string name, struct node* &head, struct node* &tail)
{
   node* newNode = new node;
   newNode->name = name;

   if (!head)
   {
      newNode->next = newNode->prev = newNode;
      head = tail = newNode;
   }

   else
   {
      newNode->next = tail->next;
      tail->next = newNode;
      newNode->next->prev = newNode;
      newNode->prev = tail;
      tail = newNode;
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


///Deletes nodes and takes care if userNum > ListSize
void deleteNodes(unsigned number, struct node* &head, struct node* &tail)
{
   if ( number > countNodes(head, tail) )
   {
      cout << "Unable to delete "    << number << " items..." << endl;
      number = countNodes(head, tail);
      cout << "Instead will delete " << number << " items..." << endl;
   }

   for (unsigned i = 0; i < number; ++i)
      deleteFirstNode(head, tail);

}

///Deletes head
///No need to protect, protected in DeleteNodes()
void deleteFirstNode(struct node* &head, struct node* &tail)
{
   struct node* curr = head;

   if (head == tail)
      head = tail = NULL;

   else
   {
      head = head->next;

      ///Assigning next and prev for nearby Nodes
      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;
   }

   delete curr;
}


///Count List Size
unsigned countNodes(struct node* &head, struct node* &tail)
{
   ///No head => size = 0
   if (!head)
      return 0;


   unsigned counter = 1;
   struct node* curr = head->next;

   while (curr != head)
   {
      ++counter;
      curr = curr->next;
   }

   return counter;
}

