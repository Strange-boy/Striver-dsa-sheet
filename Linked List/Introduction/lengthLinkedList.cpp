#include <bits/stdc++.h>
using namespace std;

//in order to create a node
class Node{
    public: 
        int data;
        Node* next;

    //when the address is given
    public:
        Node(int currData, Node* currAddr){
            data = currData;
            next = currAddr;
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
    //in order to point to current node
    Node* mover = head;

    //in order to convert 
    for(int idx = 1; idx < arr.size(); idx += 1){
        Node* temp = new Node(arr[idx]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}

//in order to find the length of the linked list
int findLength(Node* head){
    Node* temp = head;
    int length = 0;

    while(temp != nullptr){
        length += 1;
        temp = temp -> next;
    }

    return length;
}

int main(){
    int length;
    cin >> length;

    vector<int> arr(length);

    //in order to input the elements
    for(auto &value: arr){
        cin >> value;
    }

    Node* head = convertArrayToLinkedList(arr);
    int count = findLength(head);

    //the length of the linked list 
    cout << count;
}