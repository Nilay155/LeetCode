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
        
        while(temp) {
            temp = temp -> next;
            count += 1;
        }
        return count;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        
        // reverse groups of size = 2
        int length = getLen(head);
        int groups = length / 2;
        
        ListNode* p = nullptr;
        ListNode* c = head;
        ListNode* f = head -> next;
        ListNode* last = nullptr;
        ListNode* ans = nullptr;
        int count = 0;
        
        while(groups--) {
            int sz = 2;
            ListNode* ch = c;
            while(sz--) {
                ListNode* t = c;
                c -> next = p;
                c = f;
                if(f) f = f -> next;
                p = t;
            }
            
            if(count > 0) {
                last -> next = p;
            } else {
                ans = p;
            }
            count += 1;
            p = nullptr;
            last = ch;
        } 
        if(c) last -> next = c;
        return ans;
    }
};