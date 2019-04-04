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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* hp = head;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val <= p2->val)
            {
                hp->next = p1;
                p1 = p1->next;
                hp = hp->next;
                hp->next = NULL;
            }
            else
            {
                hp->next = p2;
                p2 = p2->next;
                hp = hp->next;
                hp->next = NULL;
            }
        }
        while (p1 != NULL)
        {
            hp->next = p1;
            p1 = p1->next;
            hp = hp->next;
            hp->next = NULL;
        }
        while (p2 != NULL)
        {
            hp->next = p2;
            p2 = p2->next;
            hp = hp->next;
            hp->next = NULL;
        }
        
        return head->next;
    }
};
