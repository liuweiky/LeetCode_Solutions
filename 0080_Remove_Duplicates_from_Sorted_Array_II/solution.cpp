class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, dup_cnt = 1;
        
        if (nums.size() <= 2)
            return nums.size();
        
        for (int j = 1; j < nums.size();)
        {
            if (dup_cnt < 2)
            {
                if (nums[i] == nums[j])
                    dup_cnt = 2;
                else
                    dup_cnt = 1;
                nums[++i] = nums[j++];
            }
            else if (nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                dup_cnt = 1;
                nums[++i] = nums[j++];
            }
            
        }
        return i + 1;
    }
};
