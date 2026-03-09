/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> topNode;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second;
            if(topNode.find(hd)==topNode.end()){
                topNode[hd]=frontNode->data;
            }
            if(frontNode->left){
                q.push({frontNode->left,hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hd+1});
            }
        }
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};