/*
class Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int key) {
        // code here
        if(head==NULL){
            return NULL;
        }
        Node* curr = head;
        Node* prev = NULL;
        if(head->data==key){
            if (head->next == head) {
                delete head;
                return NULL;
            }
             Node* last = head;
            while (last->next != head){
                last = last->next;
            }
            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            
            return head;
        }
        prev = head;
        curr = head->next;
        
        while (curr != head) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return head;
            }
            prev = curr;
            curr = curr->next;
        }
        
        return head;
        
    }
};