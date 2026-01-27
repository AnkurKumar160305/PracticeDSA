#include<bits/stdc++.h>
using namespace std;

//Brute force
// int rowWithMax1s(vector<vector<int>>& matrix,int n,int m){
//     int maxCount=-1;
//     int rowIndex=-1;
//     for(int i=0;i<n;i++){
//         int count=0;
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]==1){
//                 count++;
//             }
//         }
//         if(count>maxCount){
//             rowIndex=i;
//             maxCount=count;
//         }
//     }

//     return rowIndex;
// }


//Optimal
int firstOne(vector<int>& row){
    int low=0,high=row.size()-1,ans=row.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(row[mid]==1){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}


int rowWithMax1s(vector<vector<int>>& matrix,int n,int m){
    int index=-1;
    int maxOnes=-1;
    for(int i=0;i<n;i++){
        int firstIndex=firstOne(matrix[i]);
        int numberOfOnes=m-firstIndex;
        if(numberOfOnes>maxOnes){
            maxOnes=numberOfOnes;
            index=i;
        }
    }
    return index;
}



//Most Optimal
int rowWithMax1s(vector<vector<int>>& matrix, int n, int m) {
    int row = 0, col = m - 1;
    int maxRow = -1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == 1) {
            maxRow = row;
            col--;
        } else {
            row++;    
            
        }
    }
    return maxRow;
}


int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
}