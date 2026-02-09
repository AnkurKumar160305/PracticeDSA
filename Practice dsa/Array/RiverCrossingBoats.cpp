int solveBoats(int n, int x, vector<int>& w) {
    sort(w.begin(), w.end());

    int i = 0, j = n - 1;
    int boats = 0;

    while (i <= j) {
        if (w[i] + w[j] <= x) {
            i++;        // lightest paired
            j--;        // heaviest paired
        } else {
            j--;        // heaviest alone
        }
        boats++;
    }

    return boats;
}

