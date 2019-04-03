class Solution {
public:
    int len;
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        len = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for (int s = 0; s < len; s++)
        {
            if (s > 0 && nums[s - 1] == nums[s])
                continue;
            
            if (nums[s] * 4 > target)
                break;
            
            for (int t = s + 1; t < len; t++)
            {
                if (t != s + 1 && nums[t - 1] == nums[t])
                    continue;
                int remain = target - nums[s] - nums[t];
                int left = t + 1, right = len - 1;
                
                
                while (left < right)
                {
                    if (nums[left] + nums[right] == remain)
                    {
                        vector<int> v;
                        v.push_back(nums[s]);
                        v.push_back(nums[t]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ans.push_back(v);
                        left++;
                        while (left < len && nums[left] == nums[left - 1])
                            left++;
                        right--;
                        while (right > t && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (nums[left] + nums[right] < remain)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
};
