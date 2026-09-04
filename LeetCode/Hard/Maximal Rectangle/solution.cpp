class Solution {
public:
    int largestrectangle(vector<int>&arr){
        int n =arr.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<=n;i++){
            int ch =0;
            if(i==n){
                ch=0;
            }else{
                ch=arr[i];
            }
            while(!st.empty() && arr[st.top()]>ch){
                    int h =arr[st.top()];
                    st.pop();
                    int width=0;
                    if(st.empty()){
                        width=i;
                    }else{
                       width =  i-st.top()-1;
                    }
                    int area = h*width;
                    maxi = max(area,maxi);
            }
            if(i < n) {
                st.push(i);
            }
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m =matrix[0].size();
        vector<int>heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }
            }
            int area = largestrectangle(heights);
        maxi=max(area,maxi);
        }
        return maxi;
        
    }
};