// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int cnt=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
//                 if(sum==goal){
//                     cnt++;
//                 }
//                 if(sum>goal){
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        int n=nums.size();
        int r=0;
        
        unordered_map<int,int>mp;
        mp[0]=1;
        int s=0;
        while(r<n){
            s+=nums[r];
            
            int req=s-goal;
            if(mp.find(req)!=mp.end()){
                cnt+=mp[req];
            }
            mp[s]++;
            r++;
        }
        return cnt;
    }
};