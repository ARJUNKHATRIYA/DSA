class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin(),bt.end());
        int avgtime=0;
        int tat=0;
        int wt=0;
        for(int i=0;i<n;i++){
            // int tat = ct-at;
            // int wt = tat-bt;
             tat +=bt[i];
             wt = tat-bt[i];
             avgtime+=wt;
        }
        int ans = avgtime/n ;
        return ans;
        
    }
};