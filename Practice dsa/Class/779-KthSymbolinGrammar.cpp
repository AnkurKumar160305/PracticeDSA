class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1){
            return 0;
        }
        int parent=kthGrammar(n-1,(k+1)/2);

        if(k%2==1){
            return parent;
        }else{
            return 1-parent;
        }

        // 0
        // 01
        // 0110
        // 0110 1001
        // 0110 1001 1001 0110
        // 0110 1001 1001 0110 1001 0110 0110 1001
    }
};