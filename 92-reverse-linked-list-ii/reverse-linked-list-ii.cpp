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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head -> next == nullptr || left == right) return head;
        
        int count = 1;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* ans = nullptr;
        while(temp) {
            ListNode* p = nullptr;
            ListNode* c = temp;
            ListNode* f = temp -> next;
            ListNode* tail = nullptr;
            bool flag = false;

            while(count >= left && count <= right) {
                flag = true;
                if(tail == nullptr) tail = c;
                ListNode* t = c;
                c -> next = p;
                c = f;
                if(f) f = f -> next;
                p = t;
                count += 1;
            }
            if(flag) {
                if(c) tail -> next = c;
                if(prev) prev -> next = p;
                else ans = p;
                break;
            }
            prev = temp;
            temp = temp -> next;
            count += 1;
        }
        if(ans) return ans;
        else return head;
    }
};