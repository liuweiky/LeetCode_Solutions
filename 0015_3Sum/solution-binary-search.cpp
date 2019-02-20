class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int p = 0, q, r;
        while (p <= len - 3 && nums[p] <= 0)
        {
            if (p != 0 && nums[p - 1] == nums[p])
            {
                p++;
                continue;
            }
            
            for (q = p + 1; q <= len - 2; q++)
            {
                if (q != p + 1 && nums[q - 1] == nums[q])
                    continue;
                int low = q + 1, high = len - 1;
                while (low <= high)
                {
                    r = (low + high) / 2;
                    if (nums[p] + nums[q] + nums[r] < 0)
                        low = r + 1;
                    else if (nums[p] + nums[q] + nums[r] > 0)
                        high = r - 1;
                    else
                    {
                        vector<int> v;
                        v.push_back(nums[p]);
                        v.push_back(nums[q]);
                        v.push_back(nums[r]);
                        ans.push_back(v);
                        break;
                    }
                }
            }
            p++;
        }
        return ans;
    }
};
