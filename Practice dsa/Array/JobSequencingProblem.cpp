class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        int maxi=0;
        
        for(auto i:deadline){
            maxi = max(maxi, i);
        }
        
        
        vector<bool> done(n, false);
        int sum=0;
        int jobs=0;
        
        for(int i=maxi;i>=1;i--){
            
            int bestp=0;
            int index=-1;
            
            for(int j=0;j<n;j++){
                if(!done[j] && deadline[j] >= i){
                    if(profit[j]>bestp){
                        bestp=profit[j];
                        index=j;
                    }
                }
            }
            if(index!=-1){
                sum+=bestp;
                jobs++;
                done[index]=true;
            }
        }
        
        
        return {jobs,sum};
    }
};