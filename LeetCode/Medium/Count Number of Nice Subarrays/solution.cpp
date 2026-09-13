// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n=nums.size();
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             int odd=0;
//             for(int j=i;j<n;j++){
//                 if(nums[j]%2!=0){
//                     odd++;
//                 }
//                 if(odd==k){
//                     cnt++;
//                 }
//                 if(odd>k){
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int r=0,l=0;
        int odd=0;
        int even=0;
        while(r<n){
            if(nums[r]%2!=0){
                odd++;
                
            }
            
            while(odd>k){
                if(nums[l]%2!=0){
                    
                    odd--;
                }
                l++;
                even=0;
            }

            if(odd==k){
                while (l <= r && nums[l] % 2 == 0) {
                    l++;
                    even++;
                }
                cnt+=even+1;
            }
            r++;
        }
        return cnt;
    }
};