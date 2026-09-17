class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int n = intervals.size();

        // Handle empty intervals
        if (n == 0) {
            return {newInterval};
        }

        // Copy original intervals
        vector<vector<int>> ans = intervals;

        // --------------------------------------------------
        // Case 1: newInterval comes completely before
        // --------------------------------------------------
        if (newInterval[1] < intervals[0][0]) {

            ans.insert(ans.begin(), newInterval);
        }

        // --------------------------------------------------
        // Case 2: newInterval comes completely after
        // --------------------------------------------------
        else if (newInterval[0] > intervals[n - 1][1]) {

            ans.push_back(newInterval);
        }

        // --------------------------------------------------
        // Case 3: newInterval overlaps with intervals
        // --------------------------------------------------
        else {

            vector<vector<int>> temp;

            // First add intervals that are completely before
            for (int i = 0; i < n; i++) {

                if (intervals[i][1] < newInterval[0]) {
                    temp.push_back(intervals[i]);
                }
                else {
                    break;
                }
            }

            // Merge all overlapping intervals with newInterval
            for (int i = 0; i < n; i++) {

                if (intervals[i][1] >= newInterval[0] &&
                    intervals[i][0] <= newInterval[1]) {

                    newInterval[0] =
                        min(newInterval[0], intervals[i][0]);

                    newInterval[1] =
                        max(newInterval[1], intervals[i][1]);
                }
            }

            // Add merged new interval
            temp.push_back(newInterval);

            // Add intervals completely after
            for (int i = 0; i < n; i++) {

                if (intervals[i][0] > newInterval[1]) {
                    temp.push_back(intervals[i]);
                }
            }

            ans = temp;
        }

        return ans;
    }
};