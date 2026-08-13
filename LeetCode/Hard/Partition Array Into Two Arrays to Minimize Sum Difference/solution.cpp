class Solution {
public:

    // int bruteForce(vector<int>& nums,int i,int count,int sumA,int total) {
    //     int N = nums.size();
    //     int n = N / 2;
    //     // We have processed all elements
    //     if (i == N) {

    //         if (count == n) {

    //             int sumB = total - sumA;

    //             return abs(sumA - sumB);
    //         }
    //         return INT_MAX;
    //     }
    //     // Too many elements selected for A
    //     if (count > n)
    //         return INT_MAX;
    //     // Not enough elements left to fill A
    //     if (count + (N - i) < n)
    //         return INT_MAX;

    //     int take = bruteForce(nums,i + 1,count + 1,sumA + nums[i],total);
    //     int notTake = bruteForce(nums,i + 1,count,sumA,total);
    //     return min(take, notTake);
    // }

    // int minimumDifference(vector<int>& nums) {
    //     int total = 0;
    //     for(int i=0;i<nums.size();i++){
    //         total+=nums[i];
    //     }
        
    //     return bruteForce(nums,0,0,0,total);
    // }
     int minimumDifference(vector<int>& nums) {

        int N = nums.size();
        int n = N / 2;

        long long total = 0;
        for (int x : nums)
            total += x;

        // left[k] = all subset sums by choosing exactly k
        // elements from the left half
        vector<vector<long long>> left(n + 1);

        // right[k] = all subset sums by choosing exactly k
        // elements from the right half
        vector<vector<long long>> right(n + 1);

        // Generate all subsets of one half
        auto generate = [&](int start, int end,
                            vector<vector<long long>>& v) {

            for (int mask = 0;
                 mask < (1 << (end - start));
                 mask++) {

                long long sum = 0;
                int count = 0;

                for (int j = start; j < end; j++) {

                    if (mask & (1 << (j - start))) {
                        sum += nums[j];
                        count++;
                    }
                }

                v[count].push_back(sum);
            }
        };

        // Generate left and right subsets
        generate(0, n, left);
        generate(n, N, right);

        // Sort right side for binary search
        for (int k = 0; k <= n; k++) {
            sort(right[k].begin(), right[k].end());
        }

        long long ans = LLONG_MAX;

        // Select exactly n elements in first array
        for (int k = 0; k <= n; k++) {

            // k elements from left
            // n-k elements from right
            auto& A = left[k];
            auto& B = right[n - k];

            for (long long sumLeft : A) {

                // We want:
                //
                // sumLeft + sumRight ≈ total / 2
                //
                // Therefore:
                //
                // sumRight ≈ total/2 - sumLeft

                long double target =
                    (long double)total / 2.0
                    - sumLeft;

                auto it = lower_bound(
                    B.begin(),
                    B.end(),
                    target
                );

                // Candidate 1
                if (it != B.end()) {

                    long long sumA =
                        sumLeft + *it;

                    long long diff =
                        llabs(total - 2 * sumA);

                    ans = min(ans, diff);
                }

                // Candidate 2
                if (it != B.begin()) {

                    --it;

                    long long sumA =
                        sumLeft + *it;

                    long long diff =
                        llabs(total - 2 * sumA);

                    ans = min(ans, diff);
                }
            }
        }

        return (int)ans;
    }
};