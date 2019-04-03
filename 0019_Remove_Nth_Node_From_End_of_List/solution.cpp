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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* beg = new ListNode(-1);
        beg->next = head;
        ListNode* pprev = beg;
        ListNode* p = beg;
        
        int i = 0;
        
        for (i = 0; i < n + 1 && p != NULL; i++)
            p = p->next;
        if (i != n + 1)
            return head;
        
        while (p != NULL)
        {
            p = p->next;
            pprev = pprev->next;
        }
        
        pprev->next = pprev->next->next;
        
        return beg->next;
    }
};
