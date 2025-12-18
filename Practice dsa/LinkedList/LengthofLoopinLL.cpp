class Solution {
public:
    int LengthOfLL(ListNode *head) {
        if (head == NULL) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                int cnt=1;
                ListNode* temp=slow->next;
                while(temp!=slow){
                    cnt++;
                    temp=temp->next;
                }
                return cnt;
            }
        }

        return 0;
    }
};
