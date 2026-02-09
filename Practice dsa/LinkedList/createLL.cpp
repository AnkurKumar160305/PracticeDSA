// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
  Node(int d){
      this->data=d;
      this->next=NULL;
  }
};

Node* createList(Node* &head,vector<int> arr){
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* curr=new Node(arr[i]);
        temp->next=curr;
        temp=curr;
    }
    return head;
}

int main() {
    vector<int> arr={1,2,3,4};
    Node* head=new Node(arr[0]);
    createList(head,arr);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
    
}