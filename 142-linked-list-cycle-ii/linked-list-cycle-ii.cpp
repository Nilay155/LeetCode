/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* loopHead(ListNode* slow,ListNode* head) {
        ListNode* temp = head;

        while(temp != slow) {
            temp = temp -> next;
            slow = slow -> next;
        }
        return slow;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                return loopHead(slow,head);
            }
        }
        return nullptr;
    }
};