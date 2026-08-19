class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total =0;
        for(auto s:nums){
            total+=s;
        }
        
        
        int s1 = (total+target)/2;
        if(abs(target)>total) return 0;
        if((total+target)%2!=0) return 0;
      
        
        
        vector<vector<int>>dp(n+1,vector<int>(s1+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int sum=0;sum<=s1;sum++){
                dp[i][sum]=dp[i-1][sum];
                
                 if (nums[i - 1] <= sum) {

                    dp[i][sum] +=
                        dp[i - 1][
                            sum - nums[i - 1]
                        ];
                }

            }
        }
        return dp[n][s1];

    }
};