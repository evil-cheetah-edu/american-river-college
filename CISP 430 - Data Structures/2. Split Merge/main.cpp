#include <iostream>
#include <fstream>


using namespace std;


/// Unable to pass `ifstream` as parameter
ifstream in("input.txt");


/// Linked List Node struct
struct node
{
    string data;
    node* next;
};


void  addNode(node* &head, string data);
void  ReadFile(node* &head);
void  SplitMerge(node* mList, node* list1, node* list2);
void  Traverse(node* head);
node* Merge(node* &list1, node* &list2);


int main()
{
    ///list to NULL to avoid SEG_FAULT
    node *mainList = nullptr,
            *List1 = nullptr,
            *List2 = nullptr;

    ReadFile(mainList);

    ///for check only
    cout << "mainList: ";
    Traverse(mainList);
    cout << endl;

    SplitMerge(mainList, List1, List2);

    return 0;
}



void addNode(node* &head, string data)
{
    ///Allocates memory and assigns
    node* nNode = new node;
    nNode->data = data;
    nNode->next = nullptr;

    ///Is it empty?
    if (!head)
        head = nNode;

    ///No?
    else
    {
        node* curr = head;
        ///Goto end of the list
        while ( curr->next )
            curr = curr->next;

        ///End = nNode
        curr->next = nNode;
    }
}



void ReadFile(node* &head)
{
    string fileData;
    ///in >> fileData to avoid going in code block at EOF
    ///at the same time assigns the data from File to var
    while ( in >> fileData )
    {
        addNode(head, fileData);
    }
}



void  SplitMerge(node* mList, node* list1, node* list2)
{
    node       *curr = mList;
    node *mergedList = nullptr;

    ///checks if the list is empty
    if ( !curr )
        throw int(100);

    ///If passed then at least 1 thing is on the list
    unsigned numItems = 1;

    ///counts the num of items
    for (; curr->next; numItems++)
        curr = curr->next;

    ///From directions: "...divides ... linked list into two equal sublists..."
    ///Check if even
    if ( (numItems % 2) == 1)
        throw unsigned(200);

    ///changes curr to the beginning
    curr = mList;

    ///sets first half based on counter
    for(unsigned i = 0; i < (numItems / 2); ++i)
    {
        addNode(list1, curr->data);
        curr = curr->next;
    }

    ///set second half based on curr status
    while (curr)
    {
        addNode(list2, curr->data);
        curr = curr->next;
    }

    ///output first one
    cout << "list1: ";
    Traverse(list1);

    ///output second one
    cout << "list2: ";
    Traverse(list2);
    cout << endl;


    ///Merge and output
    mergedList = Merge(list1, list2);
    cout << "mergedList: ";
    Traverse(mergedList);
}



void Traverse(node* head)
{
    while (head)
    {
        cout << head->data << ' ';
        string temp = head->data;
        head = head->next;
    }
    cout << endl;
}



node* Merge(node* &list1, node* &list2)
{
    node* merged = nullptr;
    node* curr = list1;

    while (curr)
    {
        addNode(merged, curr->data);
        curr = curr->next;
    }
    curr = list2;

    while (curr)
    {
        addNode(merged, curr->data);
        curr = curr->next;
    }

    return merged;
}