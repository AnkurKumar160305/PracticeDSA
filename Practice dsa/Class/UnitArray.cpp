#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int neg = 0, pos = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == -1) neg++;
            else pos++;
        }

        int ans = 0;

        while (neg > pos) {
            int k=(neg-pos+1)/2;
            ans+=k;
            neg-=k;
            pos+=k;
        }

        if (neg % 2) {
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}