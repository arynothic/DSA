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
    vector<int> arr={2,45,32,4,5,6};
    Node* head = convertArr2LL(arr);
    print(head);
}