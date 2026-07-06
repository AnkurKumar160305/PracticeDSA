#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int> sumStore;
	int n=arr.size();

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(),sumStore.end());
	
	return sumStore[sumStore.size()-k];
}



//optimal
#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k){

	int n=arr.size();
	int totalSubarrays = n * (n + 1) / 2;

    if (k <= 0 || k > totalSubarrays){
        return -1;
	}

	priority_queue<int,vector<int>,greater<int>> pq;

	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(pq.size()<k){
				pq.push(sum);
			}else if(sum>pq.top()){
				pq.pop();
				pq.push(sum);
			}
		}
	}

	return pq.top();
}