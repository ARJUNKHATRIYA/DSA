class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return "";
        int cnt =0;
        int r=0;
        int l=0;
        int minlen= INT_MAX;
        int si=-1;
        int hash[256]={0};
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0){
                cnt=cnt+1;
            }
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen =r-l+1;
                    si=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt=cnt-1;
                }
                
                l++;
            }
            r++;
        }
    if (si == -1)
            return "";

        // Return substring starting at si of length minlen
        return s.substr(si, minlen);
    }
};