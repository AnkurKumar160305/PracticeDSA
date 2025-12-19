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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        if (n == cnt) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int len=cnt-n;
        ListNode* curr=head;
        int count=0;
        while(count<len-1){
            count++;
            curr=curr->next;
        }
        ListNode* rem=curr->next;
        curr->next=rem->next;
        delete rem;

        return head;
    }
};