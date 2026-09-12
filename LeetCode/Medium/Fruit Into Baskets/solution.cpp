// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int n = fruits.size();
//         int maxi = 0;
//         for (int i = 0; i < n; i++) {
//             unordered_set<int>st;
            
//             for (int j = i; j < n; j++) {

//                 st.insert(fruits[j]);
//                 if(st.size()>2){
//                     break;
//                 }
//                 maxi = max(maxi,j-i+1);

//             }
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxi = 0;
        int l=0,r=0;
        unordered_map<int,int>mp;
        while(r<n) {
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};