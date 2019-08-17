class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr0 = 0, ptr1 = 0/*, ptr2 = 0*/;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (ptr0 == i)
                    continue;
                
                swap(nums[ptr0], nums[i]);
                ptr0++;
                
                if (ptr1 < ptr0)
                    ptr1 = ptr0;
                
                /*if (ptr2 < ptr0)
                    ptr2 = ptr0;*/
                
                i--;
            }
            else if (nums[i] == 1)
            {
                if (ptr1 == i)
                    continue;
                swap(nums[ptr1], nums[i]);
                ptr1++;
                
                /*if (ptr2 < ptr1)
                    ptr2 = ptr1;*/
                
                i--;
            }
        }
    }
};
