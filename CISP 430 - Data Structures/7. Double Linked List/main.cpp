#include <iostream>
#include <string>
#include <fstream>


using namespace std;


ifstream in("input.txt");


enum OUTPUT_TYPE {ASCENDING, DESCENDING};


struct node
{
   node*  prev;
   string name;
   node*  next;
};


void   readIn(struct node* &head, struct node* &tail);
void deleteNodeWithName(string input, struct node* &head, struct node* &tail);

bool isEqual(string a, string b);
string toLowercase(string a);

void insertDouble(string studentName, struct node* &head, struct node* &tail);
void  cleanUp(struct node* &head, struct node* &tail);

void traverse(struct node* &head, struct node* &taili, OUTPUT_TYPE type = ASCENDING);


int main()
{
    struct node *head, *tail;
    head = tail = nullptr;

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


/**
 * Reads data from file
**/
void readIn(struct node* &head, struct node* &tail)
{
    string input;

    while (in >> input)
    {
        if (input != "delete")
        {
            insertDouble(input, head, tail);
            continue;
        }

        in >> input;
        deleteNodeWithName(input, head, tail);
    }

    cout << endl << endl;
    cout << "Read in complete..." << endl << endl;
}


/**
 * Deletes a node with specified name
**/
void deleteNodeWithName(string input, struct node* &head, struct node* &tail)
{
    struct node* current = head;

    cout << "Deleting from the list: " << input << endl;

    if (!current)
    {
        cout << "List is empty..." << endl;
        return;
    }

    while (current)
    {
        if ( !isEqual(current->name, input) )
        {
            current = current->next;
            continue;
        }

        ///Is situated inbetween Head and Tail
        if (current->next && current->prev)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        ///Is situated at Position of Head
        else if (!current->prev)
        {
            current->next->prev = nullptr;
            head = current->next;
        }
        ///Is situated at position of Tail
        else if (!current->next)
        {
            current->prev->next = nullptr;
            tail = current->prev;
        }

        delete current;
        return;
    }

    cout << "There is no person on the list with name: " << input << endl;
}



/**
 * Compares 2 strings case insensitive
**/
bool isEqual(string a, string b)
{
    a = toLowercase(a);
    b = toLowercase(b);

    return a == b;
}


/**
 * From `Uppercase` to `Lowercase` using ASCII table
**/
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

    if ( !head )
    {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;

        return;
    }

    if ( studentName < head->name )
    {
        head->prev = newNode;
        newNode->prev = nullptr;
        newNode->next = head;
        head = newNode;

        return;
    }

    if ( studentName > tail->name )
    {
        tail->next = newNode;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail = newNode;

        return;
    }


    struct node* curr;
    curr = head->next;

    while (studentName > curr->name && curr)
        curr = curr->next;

    newNode->next = curr->prev->next;
    newNode->prev = curr->prev;
    newNode->prev->next = newNode;
    newNode->next->prev = newNode;
}


/**
 * Cleans up the memory
**/
void cleanUp(struct node* &head, struct node* &tail)
{
    struct node* temp = head;

    while (temp != tail)
    {
        temp = temp->next;
        delete temp->prev;
    }
    delete temp;

    head = tail = nullptr;
}


/**
 * Traverses Linked List
**/
void traverse(struct node* &head, struct node* &tail, OUTPUT_TYPE type)
{
    struct node* current;

    switch (type)
    {
        case (ASCENDING):
        {
            current = head;
            while (current)
            {
                cout << current->name << endl;
                current = current->next;
            }
            break;

        }
        case(DESCENDING):
        {
            current = tail;
            while (current)
            {
                cout << current->name << endl;
                current = current->prev;
            }
            break;
        }

        default:
            cout << "Unknown type was passed..." << endl;
    }
}
