#include <bits/stdc++.h>
using namespace std;


// in order to create a node of the linked list
class Node{
    public:
        int data;
        Node* next;

    //in order to declare the constructor
    public:
        Node(int currData, Node* nextAddr){
            data = currData;
            next = nextAddr;
        }
};

int main(){
    vector<int> nums = {2, 3, 4, 5, 6};

    //in order to get the address of the node
    Node* newNode = new Node(nums[3], nullptr);
    cout << newNode -> data << " " << newNode -> next;

}