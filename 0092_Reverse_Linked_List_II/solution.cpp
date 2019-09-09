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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if (m == n)
            return head;
        
        ListNode* soldier = new ListNode(0);
        soldier->next = head;
        
        ListNode* p = head;
        
        int idx = 1;
        
        ListNode* mp;
        ListNode* np;
        
        ListNode* prev = soldier;
        ListNode* mprev;
        
        while (idx != m)
        {
            prev = p;
            p = p->next;
            idx++;
        }
        mprev = prev;
        mp = p;
        prev = mp;
        p = p->next;
        idx++;
        
        while (idx != n + 1)
        {
            ListNode* nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
            idx++;
        }
        
        mp->next = p;
        mprev->next = prev;
        
        return soldier->next;
    }
};
