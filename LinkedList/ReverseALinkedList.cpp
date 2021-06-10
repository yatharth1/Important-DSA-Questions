#include<bits/stdc++.h>
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

node* reverseLinkedList(node *head){    

    node* previous = NULL;
    node* current = head;

    while(current != nullptr){

        node* next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }

    return previous;
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
    node* head = new node(10);
    head -> next = new node(20);
    head -> next -> next = new node(30);
    display(head);
    head = reverseLinkedList(head);
    display(head);
    return 0;
}






