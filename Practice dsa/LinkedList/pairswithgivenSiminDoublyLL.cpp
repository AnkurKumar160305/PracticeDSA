vector<pair<int,int>> findPairs(Node* head, int target) {
    vector<pair<int,int>> ans;
    if (head == NULL) return ans;

    Node* left = head;
    Node* right = head;

    // Move right to the tail
    while (right->next != NULL)
        right = right->next;

    // Two-pointer approach
    while (left != right && right->next != left) {
        int sum = left->data + right->data;

        if (sum == target) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    return ans;
}
