#include<iostream>
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

int countNoOfNodes(Node* root){
    if(root ==NULL) return 0;

    return countNoOfNodes(root -> left) + countNoOfNodes(root -> right) +1;
}

int main(){
    Node* root  = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    
    cout << countNoOfNodes(root);

}