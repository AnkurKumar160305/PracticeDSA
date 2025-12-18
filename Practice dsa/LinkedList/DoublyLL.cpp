#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;  
    Node* prev;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }  
}

void printforwardLL(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void printbackwardLL(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}


void insertatBeginning(Node* &head,int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}


void insertatEnd(Node* &head,int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
int main(){
    Node* head=new Node(0);
}