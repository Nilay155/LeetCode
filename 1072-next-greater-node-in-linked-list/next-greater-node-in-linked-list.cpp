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
private:
    ListNode* reverseLL(ListNode* head) {
        if(!head || !head -> next)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = head -> next;

        while(curr) {
            curr -> next = prev;
            prev = curr;
            curr = forward;
            if(forward)
                forward = forward -> next;
        }
        return prev;

    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* revLL = reverseLL(head);
        vector<int> ans;
        stack<int> st;

        ListNode* temp = revLL;
        while(temp) {

            while(!st.empty() && st.top() <= temp -> val)
                st.pop();
            
            if(!st.empty()) ans.push_back(st.top());
            else ans.push_back(0);

            st.push(temp -> val);
            temp = temp -> next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};