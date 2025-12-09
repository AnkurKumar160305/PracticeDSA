class Solution {
public:
    int stationsNeeded(const vector<int>& stations, double mid) {
        int count=0;
        int n=stations.size();
        for (int i = 1; i < n; i++) {
            double gap = stations[i] - stations[i-1];
            count += (int)(gap / mid);
        }
        return count;
    }

    double minmaxGasDist(vector<int>& stations, int K) {

        double left = 0;
        double right = stations.back() - stations.front(); // max gap
        double eps = 1e-6; // precision

        // Binary Search on Answer
        while (right - left > eps) {
            double mid = (left + right) / 2.0;

            if (stationsNeeded(stations, mid) <= K) {
                right = mid;  // we can try smaller max-distance
            } else {
                left = mid;   // we need more distance, increase mid
            }
        }

        return left;
    }
};