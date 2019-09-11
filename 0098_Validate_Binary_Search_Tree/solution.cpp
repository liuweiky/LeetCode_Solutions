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
    
    bool flag = true;
    
    map<TreeNode*, long long> mp_min;
    map<TreeNode*, long long> mp_max;
    
    long long get_min(TreeNode* r)
    {
        if (r == NULL)
            return LONG_LONG_MAX;
        if (mp_min.find(r) != mp_min.end())
            return mp_min[r];
        mp_min[r] = min(min((long long)r->val, get_min(r->left)), get_min(r->right));
        return mp_min[r];
    }
    
    long long get_max(TreeNode* r)
    {
        if (r == NULL)
            return LONG_LONG_MIN;
        if (mp_max.find(r) != mp_max.end())
            return mp_max[r];
        mp_max[r] = max(max((long long)r->val, get_max(r->left)), get_max(r->right));
        return mp_max[r];
    }
    
    bool dfs(TreeNode* r)
    {
        if (r == NULL)
            return true;
        
        long long lm = get_max(r->left);
        long long rm = get_min(r->right);
        
        cout << lm << ' ' << rm << endl;
        
        if (lm >= (long long)r->val || rm <= (long long)r->val)
            return false;
        
        return dfs(r->left) && dfs(r->right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        if (root == NULL)
            return true;
        
        return dfs(root);
    }
};
