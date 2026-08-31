class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }
        for(auto it :mp){
            pq.push({it.second,it.first});
        }
        
        for(int i=0;i<k;i++){
            auto it = pq.top();
            pq.pop();
            int ele = it.second;
            ans.push_back(ele);

        }
        return ans;
    }
};