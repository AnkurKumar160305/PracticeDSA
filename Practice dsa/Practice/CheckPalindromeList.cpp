/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

bool isPalindrome(Node* head) {
    // add your code here
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* prev=NULL;
    Node* curr=slow;
    Node* nextnode=NULL;
    while(curr!=NULL){
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    Node* first=head;
    Node* second=prev;
    while(second!=NULL){
        if(second->data!=first->data){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
}