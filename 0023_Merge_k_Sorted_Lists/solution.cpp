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
    
    struct cmp
    {
        bool operator () (ListNode* lhs, ListNode* rhs)
        {
            return lhs->val > rhs->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        
        for (int i = 0; i < sz; i++)
            if (lists[i] != NULL)
                q.push(lists[i]);
        
        while (!q.empty())
        {
            ListNode* tp = q.top();
            q.pop();
            tail->next = tp;
            tp = tp->next;
            if (tp != NULL)
                q.push(tp);
            tail = tail->next;
            tail->next = NULL;
        }
        
        return head->next;
    }
};
