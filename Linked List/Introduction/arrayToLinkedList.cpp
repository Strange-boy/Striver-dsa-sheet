#include <bits/stdc++.h>
using namespace std;

//in order to create a Node 
class Node{
    public: 
        int data;
        Node* next;

    //node with an address
    public:
        Node(int currData, Node* nextAddr){
            data = currData;
            next = nextAddr;
        }

    public:
        Node(int currData){
            data = currData;
            next = nullptr;
        }
};

//in order to convert an array to linked list
Node* convertArrayToLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);

    //in order to create a node every time
    Node* mover = head;

    for(int idx = 1; idx < arr.size(); idx += 1){
        Node* temp = new Node(arr[idx]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}

//in order to traverse a linked list
void traverseLinkedList(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next; 
    }
}

int main(){
    vector<int> arr = {2, 3, 4, 5, 6, 7};

    Node* head = convertArrayToLinkedList(arr);
    traverseLinkedList(head);
}