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
    ListNode* swapPairs(ListNode* head) {
        ListNode* hhead = new ListNode(-1);
        hhead->next = head;
        
        ListNode* pprev = hhead;
        ListNode* p = head;
        
        while (p != NULL)
        {
            if (p->next == NULL)
                break;
            pprev->next = p->next;
            p->next = p->next->next;
            pprev->next->next = p;
            pprev = p;
            p = p->next;
        }
        return hhead->next;
    }
};
