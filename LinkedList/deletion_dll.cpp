#include<iostream>
#include<vector>
using namespace std;
struct Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
        
    }
};

Node* delete_head(Node* head){

    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    
    delete temp;
    return head;
}

Node* delete_tail(Node* head){

    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    Node* tail = temp->next;
    
    tail->prev = nullptr;
    temp->next = nullptr;

    delete(tail);

    return head;

}

Node* k_element_delete(Node* head, int x){

    if (head == nullptr || x < 0) {
        cout << "Invalid input: List is empty or index is negative." << endl;
        return head;
    }

   
    Node* temp = head;

    for(int i=0; i<x; i++){
        if(temp == nullptr){
            cout<<"Integer is out of bound"<<endl;
            return head;
        }
        temp = temp->next;
    }

    if (temp == head) {
        head = head->next;  
        if (head != nullptr) {
            head->prev = nullptr;  
        }
        delete temp;  
        return head;
    }

    Node* back = temp->prev;
    Node* front = temp->next;

    if (back != nullptr) {
        back->next = front;
    }
    if (front != nullptr) {
        front->prev = back;
    }

    delete temp;

    return head;
}

Node* convertArr2LL(vector<int> &arr){

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head){

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

int main(){
    vector<int> arr={2,45,32,4,5,6,78,98};
    Node* head = convertArr2LL(arr);
    head = delete_head(head);
    head = delete_tail(head);
    head = k_element_delete(head,3);
    print(head);
}