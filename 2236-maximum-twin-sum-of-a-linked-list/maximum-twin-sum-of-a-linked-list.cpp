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
            count += 1;
            temp = temp -> next;
        }
        return count;
    }
    ListNode* reverseLL(ListNode* head,int count) {
        int half = count / 2;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        count = 0;
        while(count < half) {
            count += 1;
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = nullptr;
        ListNode* curr = temp;
        ListNode* forward = temp -> next;
        prev = nullptr;

        while(curr) {
            curr -> next = prev;
            prev = curr;
            curr = forward;
            if(forward) forward = forward -> next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        int length = getLength(head);
        ListNode* tail = reverseLL(head,length);
        int maxTwinSum = 0;
        while(head != nullptr) {
            maxTwinSum = max(maxTwinSum,head -> val + tail -> val);
            head = head -> next;
            tail = tail -> next;
        }
        return maxTwinSum;
    }
};