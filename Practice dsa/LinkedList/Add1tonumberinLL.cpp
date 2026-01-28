class Solution
{

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode *addOne(ListNode *head)
    {
        head = reverse(head);

        ListNode *curr = head;
        int carry = 1; // because we are adding 1
        ListNode *prev = NULL;

        while (curr && carry)
        {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr->next;
        }

        // If carry is still left, add a new node
        if (carry)
        {
            prev->next = new ListNode(carry);
        }

        head = reverse(head);
        return head;
    }

public:
    ListNode *plusOne(ListNode *head)
    {
        return addOne(head);
    }
};
