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


//Deletion from beginning
void deleteatHead(Node* &head){
    if(head==NULL) return;

    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

//Deletion from End
void deletionfromEnd(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }

    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}


//Delete by Value
void deletebyValue(Node* &head,int val){
    if (head == NULL) return;

    if (head->data == val) {
        deleteHead(head);
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL && temp->next->data!=val){
        temp=temp->next;
    }
    if (temp->next == NULL) return;
    Node* del=temp->next;
    temp=del->next;
    delete del;
}


//Length of LL
int length(Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

//Searching in LL
bool Search(Node* head,int key){
    while(head!=NULL){
        if(head->val==key){
            return true;
        }
        head=head->next;
    }
    return false;
}

//Reverse LL (Very important)
Node* ReverseLL(Node* head){
    Node* prev=NULL;
    Node* curr=head;

    while(curr!=NULL){
        Node* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
}
//Or

Node* reverseRecursive(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}


// Middle of LL (Tortoise & Hare Algorithm)
Node* middleofLL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


//Detect Cycle (very important)
bool DetectCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}


//Remove Cycle (advance)
void removeCycle(Node* head){
    Node* slow=head;
    Node* fast=head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast=head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

//Merge Two Sorted LL
Node* merge(Node* l1, Node* l2) {

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