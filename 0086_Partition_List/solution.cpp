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
    ListNode* partition(ListNode* head, int x) {
        ListNode* new_head = NULL;
        ListNode* p = head;
        
        vector<ListNode*> ns;
        ListNode* soldier = new ListNode(0);
        soldier->next = head;
        ListNode* prev = soldier;
        
        while (p != NULL)
        {
            if (new_head == NULL && p->val >= x)
                new_head = p;
            
            if (p->val < x)
            {
                ns.push_back(p);
                prev->next = p->next;
                p = p->next;
            }
            else
            {
                prev = p;
                p = p->next;
            }
        }
        
        if (ns.size() == 0)
            return head;
        
        for (int i = 1; i < ns.size(); i++)
            ns[i - 1]->next = ns[i];
        
        ns[ns.size() - 1]->next = new_head;
        return ns[0];
    }
};
