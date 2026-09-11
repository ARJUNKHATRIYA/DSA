class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        // Count frequency of each digit
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // First digit: 1-9
        for (int first = 1; first <= 9; first++) {
            if (freq[first] == 0) continue;

            freq[first]--;

            // Second digit: 0-9
            for (int second = 0; second <= 9; second++) {
                if (freq[second] == 0) continue;

                freq[second]--;

                // Last digit must be even
                for (int last = 0; last <= 9; last++) {
                    if (last % 2 == 0 && freq[last] > 0) {
                        ans++;
                    }
                }

                freq[second]++;
            }

            freq[first]++;
        }

        return ans;
    }
};