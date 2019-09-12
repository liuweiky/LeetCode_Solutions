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
    
    map<TreeNode*, int> mp;
    
    int get_height(TreeNode* r)
    {
        if (r == NULL)
            return 0;
        if (mp.find(r) != mp.end())
            return mp[r];
        
        return max(get_height(r->left), get_height(r->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        int hl = get_height(root->left);
        int hr = get_height(root->right);
        
        if (abs(hl - hr) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
