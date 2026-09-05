class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        long long maxi = LLONG_MIN;

        for (int i = 0; i < n; i++) {

            maxi = max(maxi, (long long)nums[i]);

            long long mini = LLONG_MAX;

            for (int j = i; j < n; j++) {
                mini = min(mini, (long long)nums[j]);
            }

            long long stable = maxi - mini;

            if (stable <= k) {
                return i;
            }
        }

        return -1;
    }
};