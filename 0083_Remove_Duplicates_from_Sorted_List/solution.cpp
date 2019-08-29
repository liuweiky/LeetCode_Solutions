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
        ListNode* cur = head;
        
        while (cur != NULL)
        {
            ListNode* p = cur->next;
            
            while (p != NULL && p->val == cur->val)
                p = p->next;
            cur->next = p;
            cur = p;
        }
        
        return head;
    }
};
