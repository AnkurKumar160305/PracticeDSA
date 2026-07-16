#include<bits/stdc++.h>

long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.
     priority_queue<long long int,vector<long long int>,
     greater<long long int>> pq;

     for(auto i:arr){
          pq.push(i);
     }
     long long int adding=0;
     while(pq.size()>1){
          long long int first=pq.top();
          pq.pop();
          long long int second=pq.top();
          pq.pop();
          long long int sum=first+second;
          adding+=sum;
          pq.push(sum);
     }

     return adding;

}
