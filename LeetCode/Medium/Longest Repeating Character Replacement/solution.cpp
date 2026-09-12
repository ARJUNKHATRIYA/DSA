// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//          int n = s.size();
//         int maxi = 0;
//         for(int i=0;i<n;i++){
//             int hash[26]={0};
//             int maxf=0;
//             for(int j=i;j<n;j++){
//                     hash[s[j]-'A']++;
//                     maxf = max(maxf,hash[s[j]-'A']);
//                     int changes = j-i+1-maxf;
//                     if(changes<=k){
//                         maxi = max(maxi,j-i+1);
//                     }

//             }
//         }
//         return maxi;

//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxi = 0;
        int maxf=0;
        int l=0,r=0;
        int hash[26]={0};
        while(r<n){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);
            if(r-l+1-maxf>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxf<=k){
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        
        return maxi;
    }
};