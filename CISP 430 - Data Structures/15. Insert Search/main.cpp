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


///Searches the item and outputs the path
void binarySearch(struct BinaryTree* &leaf, string key)
{
    if (!leaf)
        cout << "Wasn't able to find name: " << key;

    ///Found the match
    if (key == leaf->name)
        ///Output leaf name + the number of times it occurs in the tree
        cout << leaf->name << ' ' << numNames(leaf->names);

    else if (key < leaf->name)
    {
        cout << leaf->name << ' ';
        binarySearch(leaf->left, key);
    }
    else if (key > leaf->name)
    {
        cout << leaf->name << ' ';
        binarySearch(leaf->right, key);
    }
}


///Counts the number of repeats of a name
int  numNames(struct node* &top)
{
    ///Function call from binary search
    ///=> There is at least one item
    int counter = 1;

    ///If there is nothing in linked list
    ///There is at least the name in the TreeNode
    if (!top)
        return counter;

    ///While there is a linkedList node increase counter
    while (top)
    {
        top = top->next;
        ++counter;
    }

    return counter;
}


///Allocate new node for LinkedList
void  newNode(struct node* &top, string name)
{
    top = new node;
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
