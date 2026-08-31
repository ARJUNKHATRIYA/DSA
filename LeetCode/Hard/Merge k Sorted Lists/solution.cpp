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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>>pq;
        

        for(auto list:lists){
            ListNode* temp = list;
            while(temp!=nullptr){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail =dummy;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            tail->next = new ListNode(ele);
            tail=tail->next;
        }
        return dummy->next;
    }
};