class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> ans;
        int n = asteroids.size();

        stack<int> st;

        for(int i = 0; i < n; i++) {

            // No collision:
            // Both moving in same direction
            if(!st.empty() &&
               ((st.top() > 0 && asteroids[i] > 0) ||
                (st.top() < 0 && asteroids[i] < 0))) {

                st.push(asteroids[i]);
                continue;
            }


            // Collision can ONLY happen when:
            // stack top is positive
            // current asteroid is negative

            bool destroyed = false;

            while(!st.empty() &&
                  st.top() > 0 &&
                  asteroids[i] < 0) {

                // Current asteroid is bigger
                if(abs(st.top()) < abs(asteroids[i])) {

                    st.pop();
                }

                // Both are equal
                else if(abs(st.top()) == abs(asteroids[i])) {

                    st.pop();

                    destroyed = true;

                    break;
                }

                // Stack asteroid is bigger
                else {

                    destroyed = true;

                    break;
                }
            }


            // Current asteroid survived
            if(!destroyed) {
                st.push(asteroids[i]);
            }
        }


        // Convert stack to vector
        while(!st.empty()) {

            ans.push_back(st.top());

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};