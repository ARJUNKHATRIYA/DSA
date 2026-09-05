class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // suffixMin[i] = minimum element from i to n-1
        vector<long long> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min((long long)nums[i], suffixMin[i + 1]);
        }

        // prefix maximum
        long long maxi = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, (long long)nums[i]);

            long long instability = maxi - suffixMin[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};