class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }

        priority_queue<int>pq;
        for(int f:freq){
            if(f>0){
                pq.push(f);
            }
        }

        queue<pair<int,int>>q;
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!q.empty() && q.front().second==time){
                int remaining = q.front().first;
                q.pop();
                pq.push(remaining);
            }
            if(!pq.empty()){
                int rem = pq.top();
                pq.pop();
                rem--;
                if(rem>0){
                    q.push({rem,time+n+1});
                }
                
            }
        }
        return time;
    }
};