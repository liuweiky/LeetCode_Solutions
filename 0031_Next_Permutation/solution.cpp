class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        
        int local_peek = 0;
        
        for (local_peek = sz - 1; local_peek >= 1; local_peek--)
        {
            if (nums[local_peek - 1] < nums[local_peek])
                break;
        }
        
        if (local_peek == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int swptr = local_peek;
        
        for (int i = sz - 1; i >= local_peek; i--)
        {
            if (nums[i] > nums[local_peek - 1])
            {
                swptr = i;
                break;
            }
        }
        
        swap(nums[local_peek - 1], nums[swptr]);
        reverse(nums.begin() + local_peek, nums.end());
        
    }
};
