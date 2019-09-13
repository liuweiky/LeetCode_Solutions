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
    
    int target;
    bool flag = false;
    
    void dfs(TreeNode* r, int sum)
    {
        if (flag)
            return;
        
        if (r->left == NULL && r->right == NULL)
        {
            if (sum + r->val == target)
                flag = true;
            return;
        }
        
        if (r->left != NULL)
            dfs(r->left, sum + r->val);
        if (r->right != NULL)
            dfs(r->right, sum + r->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (root == NULL)
            return false;
        
        target = sum;
        dfs(root, 0);
        return flag;
    }
};
