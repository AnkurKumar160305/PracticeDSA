Node* trackInterviews(Node* head, string name) {
    if (!head) return head;

    Node* curr = head;
    int count = 0;

    while (curr != NULL) {
        if (curr->val == name) {
            count++;

            // Create new node with count as string
            Node* newNode = new Node(to_string(count));

            // Insert after current node
            newNode->next = curr->next;
            curr->next = newNode;

            // Move to next original node
            curr = newNode->next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}