class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int cnt=0;
        int farthest=0;
        int currentend=0;
        for(int i=0;i<n-1;i++){

            
           farthest = max(farthest,i+nums[i]);
           if(i==currentend){
                cnt++;
                currentend=farthest;
                if(currentend>=n-1){
                    return cnt;
                }
           }
        }
        return cnt;
        
    }
};