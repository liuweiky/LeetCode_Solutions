class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        
        if (sz == 0)
            return -1;
        
        int low = 0, high = sz - 1;
        
        while (low <= high)
        {
            int mid = (low + high) / 2;
            
            if (nums[mid] == target)
                return mid;
            
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid;
                else
                    high = mid - 1;
            }
        }
        
        return -1;
    }
};
