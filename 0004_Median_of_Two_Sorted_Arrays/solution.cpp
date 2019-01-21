class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& B = nums1.size() < nums2.size() ? nums2 : nums1;
        
        int m = A.size();
        int n = B.size();
        int low = 0, high = m;
        
        double ans;
        
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int i = mid;
            int j = (m + n + 1) / 2 - i;
            if (i > 0 && A[i - 1] > B[j])
            {
                high = mid - 1;
            } else if (i < m && A[i] < B[j - 1])
            {
                low = mid + 1;
            } else
            {
                int lmax, rmin;
                if (i == 0) lmax = B[j - 1];
                else if (j == 0)  lmax = A[i - 1];
                else lmax = max(A[i - 1], B[j - 1]);
                
                if ((m + n) % 2 == 1)
                {
                    ans = lmax;
                } else
                {
                    if (i == m) rmin = B[j];
                    else if (j == n)  rmin = A[i];
                    else rmin = min(A[i], B[j]);
                    ans =  (lmax + rmin) / 2.0;
                }
                break;
            }
        }
        return ans;
    }
};
