#include <iostream>
using namespace std;

struct node
{
    int data = 0;
    struct node* next;
    struct node* prev;
};

node* front = NULL;
node* rear = NULL;

void enqueue(int newdata)
{
    node* newnode = new node;

    if (front == NULL)
    {
        newnode->data = newdata;
        front = newnode;
        rear = newnode;
        rear->next = NULL;
        rear->prev = NULL;
        front->prev = NULL;
        front->prev = NULL;
    }

    else if (front != NULL)
    {
        newnode->data = newdata;
        rear->next = newnode;
        newnode->prev = rear;

        rear = newnode;
        rear->next = NULL;

        if (rear->prev == front)
        {
            front->next = newnode;
        }

    }
}

bool isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(node* displayed)
{
    while (displayed)
    {
        std::cout << displayed->data << " ";
        if (displayed->next == NULL)
        {
            std::cout << "\nEnd of queue" << std::endl;
            break;
        }
        else if (displayed->next != NULL)
        {
            displayed = displayed->next;
            std::cout << "- ";
        }
    }
}

int peek(node* front) { return front->data; }


void dequeue(node* deletor)
{
    if (front != NULL)
    {
        front = front->next;
        front->prev = NULL;
        delete deletor;
    }
}

int main()
{
    cout << isEmpty() << endl;
    enqueue(58);
    enqueue(-72);
    enqueue(9);
    display(front);
    cout << peek(front) << endl;
    cout << isEmpty() << endl;
    dequeue(front);
    cout << peek(front) << endl;
    return 0;
}