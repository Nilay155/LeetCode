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
        int getLen(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while(temp != nullptr) {
        temp = temp -> next;
        count += 1;
    }
    return count;
}
ListNode* reverseLL(ListNode* head,int len) {
    int half = len / 2 + len % 2;
    int count = 0;
    ListNode* temp = head;
    ListNode* prevTemp = nullptr;
    while(count < half) {
        count += 1;
        prevTemp = temp;
        temp = temp -> next;
    }
    // cout << temp -> val << "\n";
    prevTemp -> next = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = temp;
    ListNode* forward = temp -> next;
    
    while(curr != nullptr) {
        ListNode* node = curr;
        curr -> next = prev;
        prev = curr;
        curr =  forward;
        if(forward) forward = forward -> next;
    }
    return prev;
    
}
bool isPalindrome(ListNode* head){
    int length = getLen(head);
    if(length == 0 || length == 1) return true;
    ListNode* front = head;
    ListNode* back = reverseLL(head,length);
    int half = length / 2;
    // cout << getLen(front) << "    " << getLen(back) << "\n";    
    while(half--) {
        if(front -> val != back -> val) return false;
        front = front -> next;
        back = back -> next;
    }
    return true;
}
};