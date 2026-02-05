/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        if(head -> next == nullptr) return false;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr) {
            slow = slow -> next;
            fast = fast -> next;
            if(fast) fast = fast -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};