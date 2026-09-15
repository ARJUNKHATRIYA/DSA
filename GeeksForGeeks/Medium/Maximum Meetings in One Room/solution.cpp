class Solution {
    struct Room{
        int start;
        int end;
        int idx;
    };
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        vector<Room>arr;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            arr.push_back({s[i],f[i],i+1});
        }
        vector<int>ans;
        sort(arr.begin(),arr.end(),
        [](const Room& a, Room& b){
            if(a.end!=b.end)
            return a.end<b.end;
            
            return a.idx<b.idx;
        }
        );
        int lastend=-1;
        for(int i=0;i<n;i++){
            int st = arr[i].start;
            int ed= arr[i].end;
            
            if(st>lastend){
                ans.push_back(arr[i].idx);
                lastend=ed;
                
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};