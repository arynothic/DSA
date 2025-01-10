/*
This program performs the following tasks:
1. Defines a Node structure for creating a singly linked list.
2. Converts a given array (vector) of integers into a linked list.
3. Provides functionality to:
   a. Calculate the length of the linked list.
   b. Check if a specific value exists in the linked list.
4. Demonstrates the usage of these functions in the `main` function:
   a. Creates a linked list from a sample array.
   b. Prints all elements of the linked list.
   c. Calculates and prints the length of the linked list.
   d. Checks for the presence of a specific value (5) in the linked list and prints the result.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){ 
        data=data1;
        next=next1;
    }
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover=head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}
int LengthofLL(Node* head){
    int cnt=0;
    Node* temp= head;
    while(temp){
        
        temp = temp->next;
        cnt++;
    }
    return cnt;

}//int x=3
int checkIfpresent(Node* head, int val){
    Node* temp= head;
    while(temp){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main(){
    vector<int> arr ={2,5,8,7};
    Node* head = convertArr2LL(arr);
    Node* temp= head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    int length = LengthofLL(head);
    cout << length <<endl;
    cout << checkIfpresent(head,5);
}