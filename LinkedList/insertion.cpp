#include <iostream>
#include <vector>
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

Node* insertAtBeginning(Node* head, int k){

    Node* temp = new Node(k);
    temp->next = head;
    head = temp;

    return head;

}

Node* insertAtLast(Node* head, int k){

    Node* newNode = new Node(k);

    if(head == NULL){

        return newNode;

    }

    Node* temp = head;

    while(temp->next!=NULL){

        temp = temp->next;  

    }

    temp->next = newNode;
    return head;

}

Node* insertAtPosition(Node* head, int position, int value) {

    if (position <= 1) {

        return insertAtBeginning(head, value);

    }

    Node* newNode = new Node(value);
    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {

        temp = temp->next;

    }

    if (temp == nullptr) {

        cout << "Position out of bounds!" << endl;
        delete newNode;
        return head;

    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}

int main(){
    
    vector<int> arr ={2,5,8,7,67,89,5,54};
    Node* head = convertArr2LL(arr);
    head = insertAtBeginning(head,69);
    head = insertAtLast(head,55);  
    head = insertAtPosition(head,5,1000);
    
    Node* temp = head;

    while(temp){
        
        cout << temp->data << " ";
        temp = temp->next;

    }

}