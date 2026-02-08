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
    int getLength(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while(temp) {
            temp = temp -> next;
            count += 1;
        }
        return count;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = getLength(head);
        int q = length / k , r = length % k;

        ListNode* temp = head;
        vector<ListNode*> ans;
        while(temp || ans.size() < k) {
            int count = 0;
            ListNode* start = temp;
            ListNode* prev = nullptr;

            while(count < q) {
                count += 1;
                prev = temp;
                temp = temp -> next;
            }
            if(r) {
                prev = temp;
                temp = temp -> next;
                r -= 1;
            }
            if(prev) {
                prev -> next = nullptr;
                ans.push_back(start);
            } else {
                ans.push_back(nullptr);
            }
        }
        return ans;
    }
};