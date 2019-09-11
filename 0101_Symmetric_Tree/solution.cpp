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
    
    bool check(TreeNode* lp, TreeNode* rp)
    {
        if ((lp == NULL && rp != NULL) || (lp != NULL && rp == NULL))
            return false;
        
        if (lp == NULL && rp == NULL)
            return true;
        
        if (lp->val != rp->val)
            return false;
        
        return check(lp->left, rp->right) && check(lp->right, rp->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return check(root->left, root->right);
    }
};
