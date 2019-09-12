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
    
    TreeNode* construct(vector<int>& nums, int lp, int rp)
    {
        if (lp > rp)
            return NULL;
        int mid = (lp + rp) / 2;
        TreeNode* r = new TreeNode(nums[mid]);
        r->left = construct(nums, lp, mid - 1);
        r->right = construct(nums, mid + 1, rp);
        return r;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};
