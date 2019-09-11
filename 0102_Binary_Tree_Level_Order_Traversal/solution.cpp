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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root == NULL)
            return ans;
        
        queue<pair<TreeNode*, int>> q;
        
        int cur_lev = 0;
        vector<int> v;
        q.push(make_pair(root, 0));
        
        while (!q.empty())
        {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            if (cur_lev != p.second)
            {
                ans.push_back(v);
                v.clear();
                cur_lev = p.second;
            }
            
            v.push_back(p.first->val);
            
            if (p.first->left != NULL)
                q.push(make_pair(p.first->left, cur_lev + 1));
            if (p.first->right != NULL)
                q.push(make_pair(p.first->right, cur_lev + 1));
        }
        
        if (v.size() != 0)
            ans.push_back(v);
        
        return ans;
    }
};
