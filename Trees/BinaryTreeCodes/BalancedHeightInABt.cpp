#include <iostream>
#include <cstdlib>
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

// Brute Force Approach
// O(n^2)

/*int height(Node* root){
    if(root == NULL) return 0;

    int lh = height(root -> left);
    int rh = height(root -> right);

    return max(lh,rh) + 1;
}*/

// Optimised Approach
// O(n)

bool isBalanced(Node* root, int* height){
    if (root == NULL) return true;

    int lh = 0, rh = 0;

    if(isBalanced(root -> left, &lh) == false) return false;
    if(isBalanced(root -> right, &rh) == false) return false;

    *height = max(lh, rh) + 1;

    if(abs(lh - rh) <= 1){
        return true;
    } else{
        return false;
    }
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    Node* root2 = new Node(1);
    root2 -> left = new Node(2);
    root2 -> left -> left = new Node(3);

    int height = 0;

    if(isBalanced(root2, &height) == true){
        cout << "Balanced Tree" <<"\n";
    }else{
        cout << "Unbalanced Tree" << "\n";
    }

    return 0;
}