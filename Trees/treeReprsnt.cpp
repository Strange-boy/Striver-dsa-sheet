#include <bits/stdc++.h>
using namespace std;

//in order to create a structure for the tree
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }

};


int main(){
    //in order to create a root node
    struct Node* root = new Node(1);

    root -> left =  new Node(2); //left node of tree
    root -> right = new Node(3); //right node of tree

    root -> left -> right = new Node(4);
    
    cout << root -> left -> data<< '\n'; //left value 
    cout << root -> right -> data<< '\n'; //right value
    cout << root -> left -> right -> data << '\n';


}