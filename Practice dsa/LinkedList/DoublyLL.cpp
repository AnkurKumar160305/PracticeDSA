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

void insertatPosition(Node* &head,int pos,int val){
    if(pos==1){
        insertatBeginning(head,val);
        return;
    }
    int cnt=0;
    Node* temp=head;
    while(cnt<pos-1 && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL) return;

    Node* newnode=new Node(val);
    newnode->next=temp->next;
    newnode->prev=temp;

    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }

    temp->next=newnode;
}

void deletefromBeginning(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    head=head->next;

    if(head!=NULL){
        head->prev=NULL;
    }
    delete temp;
}

void deletefromEnd(Node* &head){
    if(head==NULL) return;

    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }

    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
}


void deletebyValue(Node* &head,int val){
    if(head==NULL) return;
    Node* temp=head;
    while(temp!=NULL && temp->data!=val){
        temp=temp->next;
    }

    if(temp==NULL) return;

    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }else{
        head=temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }

    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

int main(){
    Node* head=new Node(0);
}