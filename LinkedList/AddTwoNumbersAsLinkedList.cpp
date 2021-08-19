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

node* reverseList(node* head)
{
    node* prev = NULL;
    node* curr = head;
    node* next;

    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

node* AddFun(node* head1, node* head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    head1 = reverseList(head1);
    head2 = reverseList(head2);

    node* dummy = new node(0);
    node* temp = dummy;

    int carry = 0;

    while(head1 && head2 && carry)
    {
        int sum = 0;

        if(head1)
        {
            sum += head1 -> data;
            head1 = head1 -> next;
        }

         if(head2)
        {
            sum += head2 -> data;
            head2 = head2 -> next;
        }

        sum += carry;
        carry = sum / 10;

        node* Node = new node(sum % 10);
        temp -> next = Node;
        temp = temp -> next;
    }

    return reverseList(dummy -> next);
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
    node* head1 = new node(10);
    head1 -> next = new node(20);
    head1 -> next -> next = new node(30);

    node* head2 = new node(5);
    head2 -> next = new node(6);
    head2 -> next -> next = new node(7);

    node* res = new node(0);

    res = AddFun(head1, head2);

    display(res);

    return 0;

}

