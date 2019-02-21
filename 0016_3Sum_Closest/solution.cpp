class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        
        int min_dis = INT_MAX, ms = INT_MAX;
        
        for (int i = 0; i <= sz - 3; i++)
        {
            int j = i + 1, k = sz - 1;
            while (j < k)
            {
                int s = nums[i] + nums[j] + nums[k];
                
                if (s > target)
                {
                    if (min_dis > s - target)
                    {
                        min_dis = s - target;
                        ms = s;
                    }
                    k--;
                }
                else if (s < target)
                {
                    if (min_dis > target - s)
                    {
                        min_dis = target - s;
                        ms = s;
                    }
                    j++;
                }
                else
                    return s;
            }
        }
        return ms;
    }
};
