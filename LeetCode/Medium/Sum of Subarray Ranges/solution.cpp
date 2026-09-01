class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        long long sum =0;
        for(int i=0;i<n;i++){
            long long maxi = INT_MIN;
            long long mini = INT_MAX;
            for(int j=i;j<n;j++){
                maxi =max(maxi,(long long)nums[j]);
                mini=min(mini,(long long)nums[j]);
                sum = sum+maxi-mini;
            }
            
        }
        return sum;
    }
};