// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n =s.size();
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             int a=0;
//             int b=0;
//             int c=0;
//             for(int j=i;j<n;j++){
//                 if(s[j]=='a'){
//                     a++;
//                 }
//                 if(s[j]=='b'){
//                     b++;
//                 }
//                 if(s[j]=='c'){
//                     c++;
//                 }
//                 if(a>0 && b>0 && c>0){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();
        int cnt=0;
        int freq[3]={0,0,0};
        int l=0,r=0;
        while(r<n){
            freq[s[r]-'a']++;
            while(freq[0]>0 && freq[1] >0 && freq[2]>0){
                cnt+=n-r;
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
        
    }
};