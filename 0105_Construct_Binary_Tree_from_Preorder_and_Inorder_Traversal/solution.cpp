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
    
    vector<int> po, io;
    
    TreeNode* rebuild(int pl, int pr, int il, int ir)
    {
        if (pl > pr || il > ir)
            return NULL;
        
        TreeNode* r = new TreeNode(po[pl]);
        
        int k;
        
        for (int i = il; i <= ir; i++)
            if (io[i] == r->val)
            {
                k = i;
                break;
            }
        
        r->left = rebuild(pl + 1, k - il + pl, il, k - 1);
        r->right = rebuild(k - il + pl + 1, pr, k + 1, ir);
        
        return r;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        po = preorder;
        io = inorder;
        
        return rebuild(0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};
