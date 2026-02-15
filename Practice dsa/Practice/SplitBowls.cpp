bool splitBowls(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return false;

    int s = 0, e = n - 1;
    long long sum1 = arr[s];
    long long sum2 = arr[e];

    while (s < e - 1) {  // ensure at least 1 element remains in middle
        if (sum1 < sum2) {
            s++;
            sum1 += arr[s];
        }
        else if (sum1 > sum2) {
            e--;
            sum2 += arr[e];
        }
        else {
            return true;  // valid split found
        }
    }

    return sum1 == sum2;
}


bool splitBowls(const vector<int>& arr) {
    if (arr.size() < 2) {
        return false;
    }

    long long total = 0;
    for (int x : arr) {
        total += x;
    }

    if (total % 2 != 0) {
        return false;
    }

    long long pre = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        pre += arr[i];
        if (pre == total / 2) {
            return true;
        }
    }

    return false;
}
