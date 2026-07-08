/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
#include<queue>

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    int k=listArray.size();
    if(k==0){
        return NULL;
    }
    //step1:
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head=NULL;
    Node* tail=NULL;

    while(minHeap.size()>0){
        Node* top=minHeap.top();
        minHeap.pop();
        if(top->next!=NULL){
            minHeap.push(top->next);
        }
        if(head==NULL){
            //if LL is empty
            head=tail=top;
        }else{
            //insert into LL
            tail->next=top;
            tail=tail->next;
        }
    }

    return head;
}
