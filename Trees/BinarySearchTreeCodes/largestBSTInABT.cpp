#include <iostream>
#include<climits>
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

struct information{

    int size;
    int max;
    int min;
    int ans;
    bool isBST;

};

information largestBSTinBT(Node* root){

    if(root == NULL){
        return{0, INT_MIN, INT_MAX, 0, true};
    }
    if(root -> left == NULL && root -> right == NULL){
        return{1, root -> data, root-> data, 1, true};
    }

    information leftInformation = largestBSTinBT(root -> left);
    information rightInformation = largestBSTinBT(root -> right);

    information cuurent;
    cuurent.size = (1 + leftInformation.size + rightInformation.size);

    if(leftInformation.isBST && rightInformation.isBST && leftInformation.max < root -> data && rightInformation.min > root -> data){
        cuurent.min = min(leftInformation.min, min(rightInformation.min, root -> data));
        cuurent.max = max(rightInformation.max, max(leftInformation.max, root -> data));

        cuurent.ans = cuurent.size;
        cuurent.isBST = true;

        return cuurent;
    }

    cuurent.ans = max(leftInformation.ans, rightInformation.ans);
    cuurent.isBST = false;
    return cuurent;

}



int main(){

    Node* root = new Node(15);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root ->left -> left = new Node(5);

    cout <<"Largest BST in BT : " << largestBSTinBT(root).ans << endl;
    return 0;
}