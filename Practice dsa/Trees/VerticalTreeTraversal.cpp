/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        //map(horizontal_distance,level,Nodes)
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        vector<vector<int>> ans;
        
        if(root==NULL){
            return ans;
        }
        
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(frontNode->data);
            if(frontNode->left){
                q.push({frontNode->left,{hd-1,lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right,{hd+1,lvl+1}});
            }
        }
        
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
                for(auto k:j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};