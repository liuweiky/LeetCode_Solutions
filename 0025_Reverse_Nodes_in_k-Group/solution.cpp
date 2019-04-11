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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hhead = new ListNode(-1);
        hhead->next = head;
        
        ListNode* p = head;
        ListNode* prev = hhead;
        
        vector<ListNode*> ls;
        
        while (p != NULL)
        {
            ls.push_back(p);
            
            if (ls.size() == k)
            {
                ListNode* t = p->next;
                for (int i = k - 1; i >= 1; i--)
                    ls[i]->next = ls[i - 1];
                ls[0]->next = t;
                prev->next = p;
                prev = ls[0];
                ls.clear();
                p = t;
                continue;
            }
            p = p->next;
        }
        
        return hhead->next;
    }
};
