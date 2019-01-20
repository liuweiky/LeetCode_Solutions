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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(-1);
        ListNode* head = l;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode* ln = new ListNode(-1);
            l->next = ln;
            l = ln;
            l->val = l1->val + l2->val + carry;
            if (l->val >= 10)
            {
                l->val = l->val % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL)
        {
            while (l2 != NULL)
            {
                ListNode* ln = new ListNode(-1);
                l->next = ln;
                l = ln;
                l->val = l2->val + carry;
                if (l->val >= 10)
                {
                    l->val = l->val % 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                l2 = l2->next;
            }
        } else if (l2 == NULL)
        {
            while (l1 != NULL)
            {
                ListNode* ln = new ListNode(-1);
                l->next = ln;
                l = ln;
                l->val = l1->val + carry;
                if (l->val >= 10)
                {
                    l->val = l->val % 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                l1 = l1->next;
            }
        }
        if (carry == 1)
        {
            ListNode* ln = new ListNode(1);
            l->next = ln;
            l = ln;
        }
        return head->next;
    }
};