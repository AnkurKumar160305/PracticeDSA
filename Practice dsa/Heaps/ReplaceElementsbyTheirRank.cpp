#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to replace elements by their rank in the array
    vector<int> replaceWithRank(vector<int>& arr) {
        // Copy the original array for sorting
        vector<int> sortedArr = arr;

        // Sort the array
        sort(sortedArr.begin(), sortedArr.end());

        // Create a map to store rank of each unique number
        unordered_map<int, int> rankMap;

        // Initialize rank counter
        int rank = 1;

        // Assign rank to each unique element in sorted order
        for (int num : sortedArr) {
            // If this number is not already assigned a rank
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }

        // Replace each element in original array with its rank
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> arr = {1, 5, 8, 15, 8, 25, 9};

    vector<int> res = obj.replaceWithRank(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}
