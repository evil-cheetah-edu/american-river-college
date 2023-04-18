/**
 * Eugene Moshchyn
 * CISP 430 MW 3:00 - 4:25 pm
 * Prof. I. Sabzevary
 * November 10, 2019
 * Project "Insert Search"
**/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;


ifstream in("input.txt");


struct node
{
    string name;
    struct node* next;
};


struct BinaryTree
{
    string name;
    struct node* names;
    struct BinaryTree* left;
    struct BinaryTree* right;
};


///Function prototypes
BinaryTree* newTreeNode(string name);
void    insertNew(struct BinaryTree* &leaf, string name);
void binarySearch(struct BinaryTree* &leaf, string name);
int  numNames(struct node* &top);
void  newNode(struct node* &top, string name);
void pushNode(struct node* &top, string name);


int main()
{
    string input, key;
    struct BinaryTree* root = nullptr;

    while(in >> input)
        insertNew(root, input);

    cout << "What name would you like to find?" << endl;
    cin >> key;

    binarySearch(root, key);

    return 0;
}


/**
 * Constructs new Binary Tree
**/
BinaryTree* newTreeNode(string name)
{
    struct BinaryTree* node = new BinaryTree;

    node->name  = name;

    node->names = nullptr;
    node->left  = nullptr;
    node->right = nullptr;

    return (node);
}


///Insert new Node into Tree
void insertNew(struct BinaryTree* &leaf, string name)
{
    ///Does the root/node exist?
	if (!leaf)
		leaf = newTreeNode(name);

    ///If name match => push the name into linkedList
    else if(leaf->name == name)
        pushNode(leaf->names, name);

    ///If less => go Left
	else if (name < leaf->name)
	    insertNew(leaf->left, name) ;    ///Insert in left subtree.

    ///If greater => go right
	else if (name > leaf->name)
	    insertNew(leaf->right, name) ;   ///Insert in right subtree.
}


/**
 * Binary Search
**/
void binarySearch(struct BinaryTree* &leaf, string key)
{
    if ( !leaf )
    {
        cout << "Wasn't able to find name: " << key;
        return;
    }

    if (key < leaf->name)
    {
        cout << leaf->name << ' ';
        binarySearch(leaf->left, key);
        return;
    }

    if (key > leaf->name)
    {
        cout << leaf->name << ' ';
        binarySearch(leaf->right, key);
        return;
    }

    cout << leaf->name << ' ' << numNames(leaf->names);
}


///Counts the number of repeats of a name
/**
 * Returns number of items in `linked list`
 *
 * Countrer starts at 1, since the invocation
 * comes from `binarySearch`
**/
int numNames(struct node* &top)
{
    int counter = 1;

    if ( !top )
        return counter;

    while (top)
    {
        top = top->next;
        ++counter;
    }

    return counter;
}


/**
 * Creates new `node` for Linked List
**/
void  newNode(struct node* &top, string name)
{
    top       = new node;
    top->name = name;
    top->next = nullptr;
}


///Pushes new LinkedList node
void pushNode(struct node* &top, string name)
{
    ///When parsed from Tree
    ///Does linkedList exist?
    if (!top)
        newNode(top, name);

    else
    {
        while(top->next)
            top = top->next;

        newNode(top->next, name);
    }
}
