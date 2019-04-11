class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0)
            return 0;
        int cnt = 1;
        int ptr = 0;
        for (int i = 1; i < sz; i++)
            if (nums[i] != nums[ptr])
            {
                nums[++ptr] = nums[i];
                cnt++;
            }
        return cnt;
    }
};
