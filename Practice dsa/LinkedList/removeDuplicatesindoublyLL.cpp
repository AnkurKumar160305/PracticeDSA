#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
            return head;

        Node *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if(temp->val == temp->next->val)
            {
                Node* dup = temp->next;
                temp->next = dup->next;

                if (dup->next != NULL)
                    dup->next->prev = temp;

                delete dup;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};
