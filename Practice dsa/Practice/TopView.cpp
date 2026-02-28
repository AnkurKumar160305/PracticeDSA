vector<int> topView(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    map<int,int> mp;  // hd -> node value
    queue<pair<Node*, int>> q;

    q.push({root, 0});   // node, horizontal distance

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int hd = it.second;

        // store only first node of that hd
        if(mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }

        if(node->left) {
            q.push({node->left, hd - 1});
        }

        if(node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for(auto it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}