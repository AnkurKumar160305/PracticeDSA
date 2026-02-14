class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        for(int i=0;i<n;i++){
            bool flag1=true;
            bool flag2=true;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(mat[i][j]==1){
                    flag2=false;
                }
                if(mat[j][i]==0){
                    flag1=false;
                }
            }
            if(flag1 && flag2){
                return i;
            }
        }
        return -1;
    }
};

//Optimal
/*
==================== CELEBRITY PROBLEM (STACK APPROACH) ====================

DEFINITION:
A celebrity is a person who:
1) Knows NO ONE.
2) Is known by EVERYONE else.

If we represent relationships using matrix mat:
- mat[i][j] == 1 → i knows j
- mat[i][j] == 0 → i does NOT know j

--------------------------------------------------------------------------

INTUITION (ELIMINATION IDEA):

Key Observation:
If person A knows person B → A CANNOT be celebrity.
If person A does NOT know B → B CANNOT be celebrity.

So whenever we compare two people,
we can eliminate exactly one of them.

This reduces the problem size every time.

--------------------------------------------------------------------------

ALGORITHM STEPS:

STEP 1: Push all people (0 to n-1) into stack.

STEP 2: Elimination Phase
While stack has more than 1 person:
    - Pop two people A and B.
    - If A knows B → A is NOT celebrity → push B.
    - Else → B is NOT celebrity → push A.

After this phase:
Only ONE person remains.
This person is a "potential celebrity".

Time Complexity of this phase: O(n)

--------------------------------------------------------------------------

STEP 3: Verification Phase

Now we must verify the remaining candidate 't':

For every other person i:
    1) Candidate should NOT know i → mat[t][i] must be 0.
    2) Everyone must know candidate → mat[i][t] must be 1.

If either condition fails → return -1.
Else → return t.

Time Complexity of verification: O(n)

--------------------------------------------------------------------------

TOTAL TIME COMPLEXITY:
O(n) + O(n) = O(n)

SPACE COMPLEXITY:
O(n) (due to stack)

--------------------------------------------------------------------------

INTERVIEW TRICK TO REMEMBER:

"If A knows B → A out.
 If A doesn't know B → B out."

That’s the whole logic.

========================================================================== */

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        if(n == 0) return -1;
        stack<int> st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(mat[a][b]==1){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        bool flag1=true;
        bool flag2=true;
        int t=st.top();
        for(int i=0;i<n;i++){
            if(i==t){
                continue;
            }
            if(mat[t][i]==1 || mat[i][t]==0){
                return -1;
            }
        }
        return t;
    }
};