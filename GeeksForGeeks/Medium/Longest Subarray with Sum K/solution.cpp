// class Solution {
//   public:
//     int longestSubarray(vector<int>& arr, int k) {
//         // code here
//         int n =arr.size();
//         int maxi =0;
//         for(int i=0;i<n;i++){
//             int sum =0;
//             for(int j=i;j<n;j++){
//                 sum+=arr[j];
//                 if(sum==k){
//                     maxi = max(maxi,j-i+1);
//                 }
                
//             }
//         }
//         return maxi;
//     }
// };

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n =arr.size();
        unordered_map<long long ,int>mp;
        long long sum=0;
        int maxi =0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end()){
                int len = i-mp[sum-k];
                maxi = max(maxi,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        
        return maxi;
    }
};