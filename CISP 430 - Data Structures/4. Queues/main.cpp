#include <iostream>
#include <fstream>

using namespace std;


///Vars declaration
ifstream in("input.txt");


struct node
{
   int item;
   node* next;
};


void enqueue (int item, struct node *&front, struct node *&rear);
void dequeue (struct node *&front, struct node *&rear);
void readfile(struct node *&front, struct node *&rear);
void display (struct node *&front, struct node *&rear);
void deleteNonpositive(struct node *&front, struct node *&rear);


int main()
{
    struct node *front,
                *rear;

    front = rear = nullptr;

    readfile(front, rear);
    cout << "Number:" << endl;
    cout << endl<< endl;
    deleteNonpositive(front,rear);
    cout << "After deleting: " << endl;
    display(front, rear);

    in.close();
    
    return 0;
}


void enqueue(int item, struct node *&front, struct node *&rear)
{
    struct node *newNode = new node;
    
    newNode->item = item;
    newNode->next = nullptr;

    if (rear)
    { 
        rear->next = newNode;
        rear = newNode;
    }
    else
        front = rear = newNode;
}

void dequeue(struct node *&front, struct node *&rear)
{
    struct node *temp;

    if (front)
    {
        temp = front;
        front = front->next;
        delete temp;

        if (!front)
            rear = nullptr;
        }
}

///Read the vars from the file
void readfile(struct node *&front, struct node *&rear)
{
    int temp;

    while (in >> temp)
        enqueue(temp, front, rear);
}

///Display the vars and dequeue
void display(struct node *&front, struct node *&rear)
{
    while (front)
    {
        cout << front->item << " ";
        dequeue(front, rear);
    }
    cout << endl;
}

void deleteNonpositive(struct node *&front, struct node *&rear)
{
    struct node *curr = front;
   
    ///Is head node nonPositive?
    while (front->item < 0)
    {
        front = front->next;
        delete curr;
        curr = front;
    }
    
    ///All head nodes are positive
    while (curr->next)
    {
        if (curr->next->item < 1)
        {
            ///create temp to store the address of the node to delete
            struct node *temp = curr->next;

            ///Set current -> next to node after one we want to delete
            curr->next = curr->next->next;

            delete temp;
            curr = front;
        }
        
        curr = curr->next;
    }
}