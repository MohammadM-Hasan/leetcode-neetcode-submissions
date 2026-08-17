class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int usedDays = 1;
        int currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                usedDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); 
        int right = accumulate(weights.begin(), weights.end(), 0); 
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;
                right = mid - 1; // try smaller
            } else {
                left = mid + 1; // need bigger
            }
        }
        return ans;
    }
};
