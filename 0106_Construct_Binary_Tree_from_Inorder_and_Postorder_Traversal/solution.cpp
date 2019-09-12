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
        
        TreeNode* r = new TreeNode(po[pr]);
        
        int k;
        
        for (int i = il; i <= ir; i++)
            if (io[i] == r->val)
            {
                k = i;
                break;
            }
        
        r->left = rebuild(pl, k - il + pl - 1, il, k - 1);
        r->right = rebuild(k - il + pl, pr - 1, k + 1, ir);
        
        return r;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        po = postorder;
        io = inorder;
        
        return rebuild(0, postorder.size() - 1, 0, postorder.size() - 1);
    }
};
