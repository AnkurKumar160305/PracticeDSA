/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Brute Force Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> m;
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        while(curr1!=NULL){
            m[curr1];
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            if(m.find(curr2)!=m.end()){
                return curr2;
            }else{
                curr2=curr2->next;
            }
        }
        return NULL;
    }
};


//Moderate Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=(temp1==NULL)?headB:temp1->next ;
            temp2=(temp2==NULL)?headA:temp2->next ;
        }
        return temp1;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Optimal Approach
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