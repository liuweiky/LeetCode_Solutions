class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        
        if (m == 0)
            return false;
        
        int n = matrix[0].size();
        
        if (n == 0)
            return false;
        
        int low = 0, high = m * n - 1;
        
        while (low <= high)
        {
            int mid = (low + high) / 2;
            
            int i = mid / n;
            int j = mid % n;
            
            if (matrix[i][j] < target)
                low = mid + 1;
            else if (matrix[i][j] > target)
                high = mid - 1;
            else
                return true;
        }
        
        return false;
    }
};
