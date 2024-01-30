//in order to find an element in the linked list
#include <bits/stdc++.h>
using namespace std;

//in order to create a new node
class Node{
    public:
        int data;
        Node* next;

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

//in order to convert a array to linked list
Node* convertArrayToLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);

    //in order to track the new nodes
    Node* mover = head;

    for(int idx = 1; idx < arr.size(); idx += 1){
        Node* temp = new Node(arr[idx]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}

//in order to check if the element is present or not
int checkElementPresent(Node* head, int element){
    Node* temp = head;

    while(temp != nullptr){
        if(temp -> data == element)
            return 1;

        temp = temp -> next;
    }

    return 0;
}


int main(){
    int length;
    cin >> length;

    vector<int> arr(length);

    //in order to input the elements of the array
    for(auto &value: arr) cin >> value;

    //enter the target element
    int target;
    cin >> target;

    Node* head = convertArrayToLinkedList(arr);

    if(checkElementPresent(head, target) == 1) cout << "Element found";
    else cout << "Element not found";
}