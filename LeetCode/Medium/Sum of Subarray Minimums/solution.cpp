// class Solution {
// public:
    
//     int sumSubarrayMins(vector<int>& arr) {
//         int n=arr.size();
//         long long sum =0;
//         int mini = INT_MAX;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 mini =min(mini,arr[j]);
//                 sum+=mini;
//             }
//             mini=INT_MAX;
//         }
//         return sum%(1000000007);
//     }
// };
class Solution {
public:
    vector<int> nse(vector<int>& arr){
        int n =arr.size();
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int>& arr){
        int n =arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const long long MOD =1000000007;
        vector<int>ps=pse(arr);
        vector<int>ns=nse(arr);
        long long sum=0;
        for(int i=0;i<n;i++){
           long long left = i-ps[i];
           long long right = ns[i]-i;
           long long contribution = ((long long)arr[i]*left%MOD)*right%MOD;
           sum = (sum+contribution)%MOD;  
        }
        return sum;
    }
};