#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void printingLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=new Node(1);
    Node* first=new Node(2);
    Node* second=new Node(3);
    head->next=first;
    first-> next=second;
    printingLL(head);
}