/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA) { lenA++; tempA = tempA->next; }
        while(tempB) { lenB++; tempB = tempB->next; }

        tempA = headA;
        tempB = headB;

        if(lenA>lenB){
            int diff=lenA-lenB;
            while(diff--){
                tempA=tempA->next;
            }
        }else{
            int diff=lenB-lenA;
            while(diff--){
                tempB=tempB->next;
            }
        }

        while(tempA!=NULL && tempB!=NULL){
            if(tempA==tempB){
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }

        return NULL;
    }
};