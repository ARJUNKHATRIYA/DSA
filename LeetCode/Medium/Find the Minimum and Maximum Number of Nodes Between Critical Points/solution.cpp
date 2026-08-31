/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1}; // Less than 3 nodes, no critical points possible
        }

        vector<int> ans(2, -1);
        vector<int> criticalPoints;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1}; // Less than 2 critical points, no valid distances
        }

        int minDifference = INT_MAX;
        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDifference = min(minDifference, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDifference = criticalPoints.back() - criticalPoints.front();

        ans[0] = minDifference;
        ans[1] = maxDifference;
        return ans;
    }
};
