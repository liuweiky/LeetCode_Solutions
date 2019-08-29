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
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* soldier = new ListNode(0);
        soldier->next = head;
        
        ListNode* prev = soldier;
        ListNode* cur = head;
        
        while (cur != NULL)
        {
            int cnt = 0;
            ListNode* p = cur->next;
            
            while (p != NULL && p->val == cur->val)
            {
                cnt++;
                p = p->next;
            }
            
            if (cnt != 0)
            {
                prev->next = p;
                cur = p;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return soldier->next;
    }
};
