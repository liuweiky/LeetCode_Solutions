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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        
        while (!q.empty())
        {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            if (p.first->left == NULL && p.first->right == NULL)
                return p.second;
            
            if (p.first->left != NULL)
                q.push(make_pair(p.first->left, p.second + 1));
            if (p.first->right != NULL)
                q.push(make_pair(p.first->right, p.second + 1));
        }
        
        return 0;
    }
};
