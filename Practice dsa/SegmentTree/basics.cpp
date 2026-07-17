#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tree;

// Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// Range Maximum Query
int query(int node, int start, int end, int ql, int qr) {

    // Complete lie inside the query range
    if (start >= ql && end <= qr) return tree[node];

    // Complete lie outside the query range
    if (end < ql || start > qr) return INT_MIN;

    // Partial overlap
    int mid = (start + end) / 2;

    int left = query(2 * node, start, mid, ql, qr);
    int right = query(2 * node + 1, mid + 1, end, ql, qr);

    return max(left, right);
}

void update(int node, int start, int end, int index, int val) {

    // Reached the leaf node and index founded
    if (start == end) {
        arr[index] = val;
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;

    if (index <= mid){
        update(2 * node, start, mid, index, val);
    }else{
        update(2 * node + 1, mid + 1, end, index, val);
    }

    // Update the current node because one of its children has changed it can be either left or right child or can be max of both
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main() {

    int n;
    cin >> n;

    arr.resize(n);
    tree.resize(4 * n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int l, r;
        cout << "Enter range (l r): ";
        cin >> l >> r;

        cout << "Maximum = " << query(1, 0, n - 1, l, r) << endl;
    }

    return 0;
}