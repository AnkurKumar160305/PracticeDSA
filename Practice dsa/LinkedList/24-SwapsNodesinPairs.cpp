/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr = head;

        // Swap values in pairs
        while (curr != nullptr && curr->next != nullptr) {
            // Swap the values of the current node and the next node
            int temp = curr->val;
            curr->val = curr->next->val;
            curr->next->val = temp;

            // Move to the next pair
            curr = curr->next->next;
        }
        return head;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;

        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < 2) {
            temp = temp->next;
            count++;
        }
        if (count < 2) return head;


        ListNode* prev=NULL;
        ListNode* curr=head;
        count=0;
        while(curr!=NULL && count<2){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            count++;
        }
        head->next=swapPairs(curr);
        return prev;

    }
};