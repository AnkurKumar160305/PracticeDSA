/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        Node dummy(0);
        Node* temp=&dummy;
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data==temp2->data){
                temp->next=new Node(temp1->data);
                temp=temp->next;
                
                int val=temp1->data;
                while(temp1!=NULL && temp1->data==val){
                    temp1=temp1->next;
                }
                while(temp2!=NULL && temp2->data==val){
                    temp2=temp2->next;
                }
            }else if(temp1->data<temp2->data){
                temp1=temp1->next;
            }else{
                temp2=temp2->next;
            }
        }
        return dummy.next;
    }
};