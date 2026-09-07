class Solution {
public:
   
    int distinctSubseqII(string s) {
        long long MOD = 1000000007;
        long long dp=1;
        vector<long long>last(26,0);
        for(char ch : s){
            int c = ch-'a';
            long long newdp = (2*dp-last[c] +MOD)%MOD;
            last[c]=dp;
            dp = newdp;
        }
        return (dp-1+MOD)%MOD;
    }
};