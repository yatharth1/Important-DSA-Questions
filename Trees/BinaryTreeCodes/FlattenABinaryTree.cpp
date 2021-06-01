#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flattenTree(Node* root){

    if (root == NULL || (root -> left == NULL && root -> right == NULL))
    {
        return;
    }

    if(root -> left != NULL){
        flattenTree(root -> left);

        Node* temp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;

        Node* t = root -> right;
        while(t ->right != NULL){
            t = t->right;
        }

        t -> right = temp;
    }

    flattenTree(root -> right);
    
}

void inOrderPrint(Node* root){

    if(root = NULL) return;

    inOrderPrint(root -> left);
    cout << root -> data <<" ";
    inOrderPrint(root -> right);
    
}

int main(){

    Node* root = new Node(4);
    root -> left = new Node(9);
    root -> right = new Node(5);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right -> right = new Node(6);

    flattenTree(root);
    inOrderPrint(root);
    cout << endl;
    return 0;
}