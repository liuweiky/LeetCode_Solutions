class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int can_reach = 0;
        int nptr = 0;
        
        while (nptr <= can_reach && nptr < nums.size())
        {
            can_reach = max(can_reach, nptr + nums[nptr]);
            nptr++;
        }
        
        if (can_reach >= nums.size() - 1)
            return true;
        else
            return false;
    }
};
