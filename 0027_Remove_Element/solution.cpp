class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] != val)
                nums[ptr++] = nums[i];
        }
        return ptr;
    }
};
