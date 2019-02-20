class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int p = 0, q, r;
        int prev_p = INT_MAX, prev_q = INT_MAX, prev_r = INT_MAX;
        while (p <= len - 3 && nums[p] <= 0)
        {
            if (prev_p == nums[p])
            {
                p++;
                continue;
            }
            
            prev_p = nums[p];
            prev_q = INT_MAX;
            prev_r = INT_MAX;
            
            q = p + 1;
            r = len - 1;
            
            while (q < r)
            {
                if (nums[r] < 0)
                    break;
                if (prev_q == nums[q])
                {
                    q++;
                    continue;
                }
                if (prev_r == nums[r])
                {
                    r--;
                    continue;
                }
                
                if (nums[p] + nums[q] + nums[r] < 0)
                {
                    prev_q = nums[q];
                    q++;
                }
                else if (nums[p] + nums[q] + nums[r] > 0)
                {
                    prev_r = nums[r];
                    r--;
                }
                else
                {
                    vector<int> v;
                    v.push_back(nums[p]);
                    v.push_back(nums[q]);
                    v.push_back(nums[r]);
                    ans.push_back(v);
                    prev_q = nums[q];
                    prev_r = nums[r];
                    q++;
                    r--;
                }
            }
            p++;
        }
        return ans;
    }
};
