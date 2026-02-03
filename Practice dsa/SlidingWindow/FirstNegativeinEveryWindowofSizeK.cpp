class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        queue<int> neg;
        vector<int> ans;
        
        int i=0,j=0;
        while(j<n){
            if(arr[j]<0){
                neg.push(arr[j]);
            }
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                if(!neg.empty()){
                    int negative=neg.front();
                    ans.push_back(negative);
                    if(neg.front()==arr[i]){
                        neg.pop();
                    }
                }else{
                    ans.push_back(0);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

















