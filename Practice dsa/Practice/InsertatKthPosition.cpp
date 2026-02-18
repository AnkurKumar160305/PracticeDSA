/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

Node* insertAtKthPosition(Node* head, int data, int k) {
    // add your code here
    Node* newnode=new Node(data);
    if(k==1){
        newnode->next=head;
        if(head!=NULL){
            head->prev=newnode;
        }
        return newnode;
    }
    int cnt=1;
    Node* temp=head;
    while(temp!=NULL && cnt<k-1){
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL){
        return head;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next=newnode;

    return head;
}