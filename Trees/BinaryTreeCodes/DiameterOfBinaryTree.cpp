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

int CalculateDiameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
         return 0;
    }
    int lh = 0, rh = 0;
    int leftDiameter = CalculateDiameter(root -> left, &lh);
    int rightDiameter = CalculateDiameter(root -> right, &rh);

    int currentDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int height = 0;
    cout << CalculateDiameter(root, &height) <<"\n";
    return 0;

}