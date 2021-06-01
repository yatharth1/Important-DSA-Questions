#include <iostream>
#include<stack>
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

void zigzagTraversal(Node* root){

    if(root == NULL) return;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        Node* temp = currentLevel.top();
        currentLevel.pop();

        if(temp){
            cout << temp -> data << " ";
        

            if(leftToRight == true){
                if(temp -> left != NULL){
                    nextLevel.push(temp -> left);
                }
                if(temp -> right != NULL){
                    nextLevel.push(temp -> right);
                }
            }

         //for right to left

            else{
                if(temp -> right != NULL){
                    nextLevel.push(temp -> right);
                }
                if(temp -> left != NULL){
                    nextLevel.push(temp -> left);
                }
            }
        }

        if(currentLevel.empty()){
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main(){
    Node* root = new Node(12);
    root -> left = new Node(9);
    root -> right = new Node(15);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(10);

    zigzagTraversal(root);
    cout << endl;
}