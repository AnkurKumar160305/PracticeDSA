int magneticClosestPairSum(vector<int>& skills, int target) {
    sort(skills.begin(), skills.end());

    int l = 0, r = skills.size() - 1;
    int bestSum = skills[l] + skills[r];
    int minDiff = abs(bestSum - target);

    while (l < r) {
        int sum = skills[l] + skills[r];
        int diff = abs(sum - target);

        if (diff < minDiff || (diff == minDiff && sum < bestSum)) {
            minDiff = diff;
            bestSum = sum;
        }

        if (sum < target)
            l++;
        else
            r--;
    }

    return bestSum;
}
