#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* arrayToBT(int arr[], int n, int index, Node* root){
    if(index < n){
        root = new Node(arr[index]);

        root -> left = arrayToBT(arr, n, 2 * index + 1, root -> left);
        root -> right = arrayToBT(arr, n, 2 * index + 2, root -> right);
    }

    return root;
}

void preorder(Node* root){
    if(root == NULL) return;

    cout << root -> data <<" ";
    preorder(root -> left);
    preorder(root -> right);
}

int main(){
    int arr[] = {7,5,4,8,9,6};
    int n = 6;
    Node* root = arrayToBT(arr, n, 0, root);
    preorder(root);

    return 0;
}