// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         int maxi = INT_MIN;
//         for(int i=0;i<n;i++){
//             int height=INT_MAX;
//             for(int j=i;j<n;j++){
//                 int length = j-i+1;
//                 height = min(height,heights[j]);
//                 int area = length*height;
//                 if(area>maxi){
//                     maxi =area;
//                 }

//             }
//         }
//         return maxi;
//     }
// };
class Solution {
public:
    vector<int> pse(vector<int>& heights){
        stack<int>st;
        int n =heights.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] =st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& heights){
        stack<int>st;
        int n =heights.size();
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] =st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi = INT_MIN;
        vector<int>ps = pse(heights);
        vector<int>ns =nse(heights);
        // for(int i=0;i<n;i++){
        //     cout<<"pse"<<"of"<<heights[i]<<"- "<<ps[i]<<endl;
        //     cout<<"nse"<<"of"<<heights[i]<<"- "<<ns[i]<<endl;
        // }
        for(int i=0;i<n;i++){
            int left = i-ps[i];
            int right = ns[i]-i;
            int area = heights[i]*(left+right-1);
            maxi=max(area,maxi);
        }
        return maxi;
    }
};