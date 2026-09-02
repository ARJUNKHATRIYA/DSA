class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>st;
        int n=num.size();
        if(k==n) return "0";
        
        for(char digit:num){
            while(!st.empty() && k>0 && st.back()>digit){
                
                    st.pop_back();
                    k--;
            }
            
            st.push_back(digit);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        if(i==st.size()) return "0";
        return string(st.begin() + i, st.end());
    }
};