#include <bits/stdc++.h>
using namespace std;

int maxRouterDistance(vector<int>& houses, int k) {
    sort(houses.begin(), houses.end());
    
    int n = houses.size();
    int low = 1;
    int high = houses[n - 1] - houses[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        int count = 1;
        int lastPos = houses[0];

        for (int i = 1; i < n; i++) {
            if (houses[i] - lastPos >= mid) {
                count++;
                lastPos = houses[i];
            }
        }

        if (count >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> houses = {1, 2, 8, 4, 9};
    int k = 3;

    cout << maxRouterDistance(houses, k);
}