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
    
    vector<TreeNode*> create(int lp, int rp)
    {
        vector<TreeNode*> res;
        if (lp > rp)
        {
            res.push_back(NULL);
            return res;
        }
        
        
        for (int i = lp; i <= rp; i++)
        {
            vector<TreeNode*> lc = create(lp, i - 1);
            vector<TreeNode*> rc = create(i + 1, rp);
            
            
            for (int j = 0; j < lc.size(); j++)
            {
                for (int k = 0; k < rc.size(); k++)
                {
                    TreeNode* n = new TreeNode(i);
                    n->left = lc[j];
                    n->right = rc[k];
                    res.push_back(n);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        if (n == 0)
            return vector<TreeNode*>();
        
        return create(1, n);
    }
};
