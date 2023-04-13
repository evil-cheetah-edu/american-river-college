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
    /// Instantiate to avoid garbage values
    node *mainList = nullptr,
            *List1 = nullptr,
            *List2 = nullptr;

    ReadFile(mainList);

    cout << "mainList: ";
    Traverse(mainList);
    cout << endl;

    SplitMerge(mainList, List1, List2);

    return 0;
}


/**
 * Create node and link data to the list
 */
void addNode(node* &head, string data)
{
    node* nNode = new node;
    nNode->data = data;
    nNode->next = nullptr;

    if (!head)
    {
        head = nNode;
        return;
    }

    node* current = head;

    while ( current->next )
        current = current->next;

    current->next = nNode;
}


/**
 * Reads the data from the file
 * 
 * For future me:
 *      Using `in >> fileData` to safely put line into
 *      variable. Avoids EOF
 * 
 */
void ReadFile(node* &head)
{
    string fileData;

    while ( in >> fileData )
        addNode(head, fileData);
}


/**
 * Splits the linkedList, traverses sublists,
 * merges them back.
 * 
 * Throws following exceptions:
 *  - int(100) - When linkedList is empty
 *  - int(200) - When linkedList has odd number of items
 */
void  SplitMerge(node* mList, node* list1, node* list2)
{
    node       *curr = mList;
    node *mergedList = nullptr;

    /// Checks for Empty
    if ( !curr )
        throw int(100);


    /// Count number of items
    unsigned numItems = 1;
    for (; curr->next; numItems++)
        curr = curr->next;

    ///Check if even
    if ( (numItems % 2) == 1)
        throw unsigned(200);


    curr = mList;

    /// First Sub-List
    for(unsigned i = 0; i < (numItems / 2); ++i)
    {
        addNode(list1, curr->data);
        curr = curr->next;
    }

    /// Second Sub-List
    while (curr)
    {
        addNode(list2, curr->data);
        curr = curr->next;
    }


    /// Output sub-lists    
    cout << "list1: ";
    Traverse(list1);

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