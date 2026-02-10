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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr=&dummy;
        while(curr->next!=NULL){
            if(curr->next->val==val){
                ListNode* del=curr->next;
                curr->next=curr->next->next;
                delete del;
            }else{
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};


//OR
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        if (head == NULL) return head;
        ListNode* curr=head;
        while(curr->next!=NULL){
            if(curr->next->val==val){
                ListNode* del=curr->next;
                curr->next=curr->next->next;
                delete del;
            }else{
                curr=curr->next;
            }
        }
        return head;
    }
};