#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtBegin(node* &head, int val)
{
    node* newNode = new node(val);
    newNode -> next = head;
    head = newNode;
}


void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node* head = NULL;
    insertAtBegin(head, 1); 
    insertAtBegin(head, 2);
    insertAtBegin(head, 3);
    display(head);
}