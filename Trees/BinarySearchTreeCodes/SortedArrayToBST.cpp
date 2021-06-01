#include <iostream>
#include <limits.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

};

Node* sortedArrayToBST(int arr[], int start, int end){

    if(start > end) return NULL;

    int mid = (start + end) / 2;    
    Node* root = new Node(arr[mid]);

    root -> left = sortedArrayToBST(arr, start, mid - 1);
    root -> right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void printPreorder(Node* root){
    if(root == NULL) return;

    cout << root -> data << " ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}

int main(){
    int arr[] = {10,20,30,40,50};
    Node* root = sortedArrayToBST(arr,0,4);
    printPreorder(root);

    return 0;
}