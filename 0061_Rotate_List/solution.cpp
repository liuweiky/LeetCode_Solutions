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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;
        ListNode* p = head;
        int cnt = 1;
        while (p->next != NULL)
        {
            p = p->next;
            cnt++;
        }
        k %= cnt;
        k = cnt - k;
        p->next = head;
        
        while (k--)
            p = p->next;
        
        head = p->next;
        p->next = NULL;
        return head;
    }
};
