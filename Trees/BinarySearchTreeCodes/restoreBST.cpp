#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *left, *right;

   Node(int val){
       data = val;
       left = NULL;
       right = NULL;
   } 
};

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** temp){
    if(root == NULL) return;

    calcPointers(root -> left, first, mid, last, temp);

    if(*temp && root -> data < (*temp) -> data){
        if(!*first){
            *first = *temp;
            *mid = root;
            }else{
                
        }
    }
}

void restoreBST(Node* root){

    Node *first, *mid, *last;
    Node *temp;

    first = NULL;
    mid = NULL;
    last =NULL;
    temp = NULL;

    calcPointers(root, &first, &mid, &last, &temp);

    // case - 1

    if(first && last){
        swap(&(first -> data), &(last -> data));
    }else if (first && mid){
        swap(&(first -> data), &(mid -> data));
    }
}


int main(){
    return 0;
}