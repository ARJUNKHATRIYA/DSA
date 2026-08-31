class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        // Frequency of each card
        unordered_map<int,int> mp;

        for(int x : hand)
            mp[x]++;

        // Min Heap: only card values
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > pq;

        for(auto it : mp)
            pq.push(it.first);

        while(!pq.empty()) {

            int first = pq.top();
            pq.pop();

            // How many groups must start with 'first'
            int count = mp[first];

            if(count == 0)
                continue;

            // Need:
            // first, first+1, first+2, ...
            for(int i = 0; i < groupSize; i++) {

                int card = first + i;

                if(mp[card] < count)
                    return false;

                mp[card] -= count;
            }
        }

        return true;
    }
};