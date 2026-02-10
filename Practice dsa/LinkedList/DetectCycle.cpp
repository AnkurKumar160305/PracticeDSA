// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

bool hasCycle(Node *head)
{
    unordered_set<Node *> m;
    Node *temp = head;
    while (temp != NULL)
    {
        if (m.find(temp) != m.end())
        {
            return true;
        }
        m.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool detectLoop(Node *head)
{
    // code here
    if (!head || !head->next)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

//Finding the starting point of the loop
Node* detectCycle(Node* head)
    {
        if (!head || !head->next) return NULL;
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // creating a cycle
    head->next->next->next = head;

    cout << hasCycle(head); // output: 1 (true)
    return 0;
}