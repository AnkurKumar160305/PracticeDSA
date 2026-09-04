//AccountsMerge
class Solution {
    class DSU{
        public:
        vector<int> parent,size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int findParent(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u]=findParent(parent[u]);
        }

        void Union(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);

            if(pu==pv) return;

            if(size[pu]>size[pv]){
                parent[pv]=parent[pu];
                size[pu]+=size[pv];
            }else{
                parent[pu]=parent[pv];
                size[pv]+=size[pu];
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);

        //Union accounts having same mail
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){

                string mail=accounts[i][j];

                if(m.find(mail)==m.end()){
                    m[mail]=i;
                }else{
                    ds.Union(i,m[mail]);
                }
            }
        }

        //storing mails with their parent index
        unordered_map<int,vector<string>> parenttomail;

        for(auto i:m){
            int node=i.second;
            string mail=i.first;
            int parent=ds.findParent(node);

            parenttomail[parent].push_back(mail);
        } 

        //To store final ans in sorted order of mails
        vector<vector<string>> ans;

        for(auto i:parenttomail){
            int parent=i.first;
            vector<string> mails=i.second;

            sort(mails.begin(),mails.end());
            vector<string> temp;

            temp.push_back(accounts[parent][0]);
            for(auto j:mails){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};