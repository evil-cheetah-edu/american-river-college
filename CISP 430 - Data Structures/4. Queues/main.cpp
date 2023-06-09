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
void traverse (struct node* front);
void deleteNonpositive(struct node *&front, struct node *&rear);


int main()
{
    struct node *front,
                *rear;

    front = rear = nullptr;

    readfile(front, rear);
   
    cout << "Numbers:" << endl;
    traverse(front);
    cout << endl;
    
    deleteNonpositive(front, rear);
    
    cout << "After deleting: " << endl;
    display(front, rear);

    in.close();
    
    return 0;
}


/**
 * Add an item to the back of the queue 
 */
void enqueue(int item, struct node *&front, struct node *&rear)
{
    struct node *newNode = new node;
    
    newNode->item = item;
    newNode->next = nullptr;

    if ( !rear )
    { 
        front = rear = newNode;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

/**
 * Removes first item from the queue 
 */
void dequeue(struct node *&front, struct node *&rear)
{
    if ( !front )
    {
        rear = nullptr;
        return;
    }
 
    struct node *temp;
    temp  = front;
    front = front->next;
    
    delete temp;
}


/**
 * Reads data into queue
 */
void readfile(struct node *&front, struct node *&rear)
{
    int number;

    while (in >> number)
        enqueue(number, front, rear);
}


/**
 * Traverses a queue without dequeuing
 */
void traverse(struct node* front)
{
    while (front)
    {
        cout << front->item << " ";
        front = front->next;
    }

    cout << endl;
}


/**
 * Traverses a queue with dequeuing
 */
void display(struct node *&front, struct node *&rear)
{
    while (front)
    {
        cout << front->item << " ";
        dequeue(front, rear);
    }

    cout << endl;
}


/**
 * Removes non-positive numbers from the queue
 * 
 * Example of the second part
 * Queue: (1) -1 3 4
 * () - Front
 * 
 * Process:
 *   1) Remember Address: [-1]
 *   2) Make Connection:  [1] -> [3]
 *   3) Delete: [-1]
 *   4) Start from the front
 */
void deleteNonpositive(struct node *&front, struct node *&rear)
{
    if ( !front )
        return;

    struct node *curr = front;
   
    /// Deteles non-positives from front
    while (front && front->item < 1)
    {
        front = front->next;
        delete curr;
        curr = front;
    }
    
    /// Deletes non-positives from the rest of the queue
    while (curr->next)
    {
        if (curr->next->item < 1)
        {
            struct node *temp = curr->next;
            curr->next = curr->next->next;

            delete temp;
            curr = front;
        }
        
        curr = curr->next;
    }
}