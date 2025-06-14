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
        if(head == NULL || head->next == NULL) return nullptr;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr != NULL) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next != NULL)
                next = next -> next;
        }
        return prev;
    }
private:
    bool plaindromeCheck(ListNode* head) {
        if(head == NULL) return true;
        if(head -> next == NULL) return true;
        if(head -> next -> next == NULL) {
            if(head -> val == head -> next -> val) return true;
            else return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* revHead = reverseLL(slow);
        ListNode* temp = head;

        while(revHead != NULL && temp != NULL) {
            if(revHead -> val != temp -> val) return false;
            revHead = revHead -> next;
            temp = temp -> next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        return plaindromeCheck(head);
    }
};