class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int ptr = 0;
        int cur = 0;
        int res = 0;
        
        while (ptr < nums.size() && ptr <= farthest)
        {
            if (cur < ptr)
            {
                res++;
                cur = farthest;
            }
            farthest = min((int)nums.size(), max(farthest, ptr + nums[ptr]));
            ptr++;
        }
        
        return res;
    }
};
