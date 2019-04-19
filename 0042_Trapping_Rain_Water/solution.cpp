class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        
        int i = 0, j = 0;
        
        int vol = 0;
        
        while (i < sz)
        {
            j = i + 1;
            int local_max = INT_MIN, max_idx;
            while (j < sz && height[j] < height[i])
            {
                if (local_max < height[j])
                {
                    local_max = height[j];
                    max_idx = j;
                }
                j++;
            }
            if (j == sz)
            {
                if (local_max != INT_MIN)
                    j = max_idx;
                else
                    return vol;
            }
            
            for (int p = i + 1; p < j; p++)
                vol += (min(height[i], height[j]) - height[p]);
            
            i = j;
            if (i == sz - 1)
                return vol;
        }
        return vol;
    }
};
