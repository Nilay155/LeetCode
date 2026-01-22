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
    ListNode* reversePairs(ListNode* head) {
        if(head == nullptr) return head; // 0 node
        if(head -> next == nullptr) return head; // 1 node

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = head -> next;

        // reverse two nodes
        curr -> next = prev;
        prev = curr;
        curr = forward;
        forward = forward -> next;
        curr -> next = prev;

        prev -> next = reversePairs(forward);
        return curr;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return reversePairs(head);
    }
};