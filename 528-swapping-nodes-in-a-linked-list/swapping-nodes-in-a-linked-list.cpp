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
    int getLinkedListLength(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while(curr) {
            length += 1;
            curr = curr -> next;
        }
        return length;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int linkedListLength = getLinkedListLength(head);
        if(linkedListLength == 1) return head;
        int k1 = 1, k2 = 1;

        ListNode* node1 = head;
        ListNode* node2 = head;

        while(k1 < k) {
            node1 = node1 -> next;
            k1 += 1;
        }     
        while(k2 <= linkedListLength - k) {
            node2 = node2 -> next;
            k2 += 1;
        }
        int temp = node1 -> val;
        node1 -> val = node2 -> val;
        node2 -> val = temp;
        return head; 
    }
};