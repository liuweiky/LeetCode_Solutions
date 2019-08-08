class Solution {
public:
    int mySqrt(int x) {
        
        if (x == 0)
            return 0;
        
        int low = 1;
        int high = 46340;   // sqrt(2147483647)
        
        int ans = 1;
        
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mid * mid < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (mid * mid > x)
            {
                high = mid - 1;
            }
            else
                return mid;
        }
        
        return ans;
    }
};
