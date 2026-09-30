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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }

        int l = 0;
        ListNode* curr = head;
        while(curr) {
            l++;
            curr = curr->next;
        }

        k = k % l;
        if(k == 0) {
            return head;
        }

        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
        }

        curr = head;
        ListNode* prev = NULL;
        for(int i = 0; i < (l - k); i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        tail->next = head;
        return curr;
    }
};