#include <iostream>
#include <vector>
using namespace std;
/*
### Function Descriptions ###
1. `convertArr2LL(vector<int>& arr)`
   - Converts an array into a singly linked list.
   - Creates a head node from the first element and iterates through the array to add nodes.

2. `removesHead(Node* head)`
   - Removes the first node (head) from the linked list.
   - Returns the updated head pointer.

3. `deleteTail(Node* head)`
   - Removes the last node (tail) from the linked list.
   - Traverses to the second-to-last node and deletes the last node.

4. `removesK(Node* head, int k)`
   - Removes the k-th node (1-based index) from the linked list.
   - Uses a counter to identify the k-th node and updates pointers to skip it.

5. `removesValueK(Node* head, int k)`
   - Removes the first node that contains the value `k`.
   - Traverses the list and deletes the matching node.

6. **Main Function**
   - Demonstrates the usage of all the above functions.
   - Converts an array into a linked list and performs various removal operations.
*/

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
Node* removesHead(Node* head){
    Node* temp = head;
    head = temp->next;
    free(temp);
    return head;
}
Node* deleteTail(Node* head){
    if(head == NULL|| head->next == NULL) {
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;

}
Node* removesK(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL) {
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node* removesValueK(Node *head, int k){
    if(head==NULL) return head;
    if(head->data == k){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL) {
        if(temp->data == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr ={2,5,8,7,67,89,5,54};
    Node* head = convertArr2LL(arr);

    
    head = removesHead(head);
    head = deleteTail(head);
    head = removesK(head,3);
    head = removesValueK(head,89);
    
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}