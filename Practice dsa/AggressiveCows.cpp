int main() {
    // Input stalls
    vector<int> stalls = {1, 2, 8, 4, 9};
    // Number of cows
    int cows = 3;

    // Create object
    Solution obj;
    // Print result
    cout << obj.aggressiveCows(stalls, cows) << endl;
    return 0;
}