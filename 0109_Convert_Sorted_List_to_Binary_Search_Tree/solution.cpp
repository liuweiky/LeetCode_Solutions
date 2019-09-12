/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* cur;
    
    TreeNode* construct(int lp, int rp)
    {
        if (lp > rp)
            return NULL;
        
        int mid = (lp + rp) / 2;
        TreeNode* r = new TreeNode(0);
        r->left = construct(lp, mid - 1);
        r->val = cur->val;
        cur = cur->next;
        r->right = construct(mid + 1, rp);
        return r;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        
        int cnt = 0;
        
        while (p != NULL)
        {
            cnt++;
            p = p->next;
        }
        
        cur = head;
        
        return construct(0, cnt - 1);
    }
};
