/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newnode=new Node(data);
        if(head==NULL){
            newnode->next=newnode;
            return newnode;
        }
        
        Node* temp=head;
        if(head->data>data){
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            return newnode;
        }
        while(temp->next!=head && temp->next->data<data){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
    }
};