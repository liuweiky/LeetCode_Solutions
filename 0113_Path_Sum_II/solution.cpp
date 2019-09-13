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
    vector<vector<int>> ans;
    
    void find(TreeNode*r, vector<int>& p, int sum)
    {
        if (r->left == NULL && r->right == NULL)
        {
            if (sum + r->val == target)
            {
                p.push_back(r->val);
                ans.push_back(p);
                p.pop_back();
            }
            return;
        }
        
        if (r->left != NULL)
        {
            p.push_back(r->val);
            find(r->left, p, sum + r->val);
            p.pop_back();
        }
        
        if (r->right != NULL)
        {
            p.push_back(r->val);
            find(r->right, p, sum + r->val);
            p.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return ans;
        
        target = sum;
        vector<int> tmp;
        find(root, tmp, 0);
        
        return ans;
    }
};
