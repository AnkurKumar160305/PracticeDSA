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

//Step1-Printing Linked List
void printingLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//Step2-Inserting form Beginning
void insertatHead(Node* &head,int val){
    Node* newnode=new Node(val);
    newnode->next=head;
    head=newnode;
}

void insertatEnd(Node* &head,int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

//Insert at given Position(1 based index)
void insertatPosition(Node* &head,int pos,int val){
    Node* newnode=new Node(val);
    if(pos==1){
        insertatHead(head,val);
        return;
    }
    int cnt=1;
    Node* temp=head;
    while(cnt<pos-1 && temp!=NULL){
        temp=temp->next;
        cnt++;
    }

    if (temp == NULL) return;
    newnode->next=temp->next;
    temp->next=newnode;


}

int main(){
    Node* head=new Node(1);
    Node* first=new Node(2);
    Node* second=new Node(3);
    head->next=first;
    first-> next=second;
    printingLL(head);
    cout<<endl;

    insertatHead(head,0);
    printingLL(head);
    cout<<endl;
    
    insertatEnd(head,4);
    printingLL(head);
}