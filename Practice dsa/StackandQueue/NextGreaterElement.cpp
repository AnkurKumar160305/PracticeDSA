#include<bits/stdc++.h>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> ans(n,-1);
	stack<int> st;

	for(int i=0;i<n;i++){
		while(!st.empty() && arr[i]>arr[st.top()]){
			ans[st.top()]=arr[i];
			st.pop();
		}
		st.push(i);
	}
	return ans;

}

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
	s.push(-1);

    for(int i=n-1;i>=0;i--){
		int curr=arr[i];
        while(s.top()<=curr){
			s.pop();
		}
		ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}


#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n,-1);
    stack<int> s;

    for(int i=0;i<n;i++){
        while(!s.empty() && arr[i]<arr[s.top()]){
            ans[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;

}
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
	s.push(-1);

    for(int i=n-1;i>=0;i--){
		int curr=arr[i];
        while(s.top()>=curr){
			s.pop();
		}
		ans[i]=s.top();
        s.push(curr);
    }
    return ans;

}